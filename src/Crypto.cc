#include "Crypto.h"
#include <openssl/ec.h>
#include <openssl/ecdh.h>
#include <openssl/evp.h>
#include <openssl/kdf.h>
#include <openssl/sha.h>
#include <openssl/err.h>  // ✅ ADD THIS
#include <stdexcept>
#include <algorithm>
#include <atomic>
#include <openssl/rand.h>
#include <random>
#include <vector>
#include <cstring>  // ✅ ADD THIS for snprintf

// Helper: fill buffer with cryptographic random bytes
static void randomBytes(std::vector<unsigned char>& buf) {
    if (buf.empty()) return;
#if __has_include(<openssl/rand.h>)
    if (RAND_bytes(buf.data(), (int)buf.size()) != 1) {
        throw std::runtime_error("RAND_bytes failed");
    }
#else
    // Fallback: best-effort using std::random_device (simulation-only)
    std::random_device rd;
    for (auto& b : buf) b = static_cast<unsigned char>(rd());
#endif
}

// FIX: centralize random byte generation with OpenSSL, fallback to std::random_device
static void fillRandom(std::vector<unsigned char>& buf) {
#if defined(OPENSSL_VERSION_NUMBER)
    if (RAND_bytes(buf.data(), (int)buf.size()) != 1)
        throw std::runtime_error("RAND_bytes failed");
#else
    std::random_device rd;
    for (auto& b : buf) b = static_cast<unsigned char>(rd());
#endif
}

// HKDF(SHA-256) helper
static std::vector<unsigned char> hkdfSha256(const std::vector<unsigned char>& ikm,
                                             const std::vector<unsigned char>& salt,
                                             const std::vector<unsigned char>& info,
                                             size_t outLen) {
    std::vector<unsigned char> out(outLen);
    EVP_PKEY_CTX* pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_HKDF, nullptr);
    if (!pctx) throw std::runtime_error("HKDF ctx alloc failed");
    if (EVP_PKEY_derive_init(pctx) <= 0) throw std::runtime_error("HKDF init failed");
    if (EVP_PKEY_CTX_set_hkdf_md(pctx, EVP_sha256()) <= 0) throw std::runtime_error("HKDF md failed");
    if (EVP_PKEY_CTX_set1_hkdf_salt(pctx, salt.data(), (int)salt.size()) <= 0) throw std::runtime_error("HKDF salt failed");
    if (EVP_PKEY_CTX_set1_hkdf_key(pctx, ikm.data(), (int)ikm.size()) <= 0) throw std::runtime_error("HKDF key failed");
    if (!info.empty()) {
        if (EVP_PKEY_CTX_add1_hkdf_info(pctx, info.data(), (int)info.size()) <= 0) throw std::runtime_error("HKDF info failed");
    }
    size_t len = outLen;
    if (EVP_PKEY_derive(pctx, out.data(), &len) <= 0 || len != outLen) throw std::runtime_error("HKDF derive failed");
    EVP_PKEY_CTX_free(pctx);
    return out;
}

// Canonical info: concat two pubkeys in sorted byte order
static std::vector<unsigned char> concatSorted(const std::vector<unsigned char>& a,
                                               const std::vector<unsigned char>& b) {
    if (a <= b) {
        std::vector<unsigned char> out = a;
        out.insert(out.end(), b.begin(), b.end());
        return out;
    } else {
        std::vector<unsigned char> out = b;
        out.insert(out.end(), a.begin(), a.end());
        return out;
    }
}

// Deterministic, unique 12-byte IV: 4 bytes of SHA256(pubkey) prefix + 8-byte counter
static void makeDeterministicIV(const std::vector<unsigned char>& myPub,
                                std::vector<unsigned char>& outIV) {
    static std::atomic<uint64_t> seq{1};
    outIV.resize(12);
    unsigned char h[32]{0};
    SHA256(myPub.data(), myPub.size(), h);
    outIV[0]=h[0]; outIV[1]=h[1]; outIV[2]=h[2]; outIV[3]=h[3];
    uint64_t c = seq.fetch_add(1, std::memory_order_relaxed);
    // big-endian counter in last 8 bytes
    for (int i=0; i<8; ++i) outIV[11 - i] = static_cast<unsigned char>((c >> (i*8)) & 0xFF);
}

Crypto::Crypto() : keypair(nullptr) {
}

Crypto::~Crypto() {
    if (keypair) {
        EC_KEY_free(keypair);
    }
}

void Crypto::generateKeyPair() {
    keypair = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);
    if (!keypair) {
        throw std::runtime_error("Failed to create EC_KEY");
    }

    if (EC_KEY_generate_key(keypair) != 1) {
        EC_KEY_free(keypair);
        throw std::runtime_error("Failed to generate EC key pair");
    }

    EC_KEY_set_asn1_flag(keypair, OPENSSL_EC_NAMED_CURVE);
}

std::vector<unsigned char> Crypto::getPublicKey() const {
    if (!keypair) {
        throw std::runtime_error("Keypair not initialized");
    }

    const EC_POINT* pub_key = EC_KEY_get0_public_key(keypair);
    if (!pub_key) {
        throw std::runtime_error("Public key not available");
    }

    const EC_GROUP* group = EC_KEY_get0_group(keypair);
    size_t len = EC_POINT_point2oct(group, pub_key, POINT_CONVERSION_UNCOMPRESSED, 
                                     nullptr, 0, nullptr);
    
    std::vector<unsigned char> buf(len);
    EC_POINT_point2oct(group, pub_key, POINT_CONVERSION_UNCOMPRESSED,
                       buf.data(), len, nullptr);
    
    return buf;
}

std::vector<unsigned char> Crypto::deriveSharedKey(const std::vector<unsigned char>& peerPubKey) {
    if (!keypair) throw std::runtime_error("Keypair not initialized");
    
    // ✅ VALIDATE INPUT SIZE
    if (peerPubKey.size() != 65) {
        char buf[128];
        snprintf(buf, sizeof(buf), "Invalid peer key size: %zu bytes (expected 65)", peerPubKey.size());
        throw std::runtime_error(buf);
    }
    
    // ✅ VALIDATE UNCOMPRESSED POINT FORMAT
    if (peerPubKey[0] != 0x04) {
        char buf[128];
        snprintf(buf, sizeof(buf), "Invalid EC point format: first byte is 0x%02X (expected 0x04)", 
                 (unsigned int)peerPubKey[0]);
        throw std::runtime_error(buf);
    }
    
    const EC_GROUP* group = EC_KEY_get0_group(keypair);
    if (!group) throw std::runtime_error("EC group missing");

    EC_POINT* peerPoint = EC_POINT_new(group);
    if (!peerPoint) throw std::runtime_error("EC_POINT_new failed");
    
    // ✅ REPLACE LINE 155 WITH THIS:
    int result = EC_POINT_oct2point(group, peerPoint, peerPubKey.data(), peerPubKey.size(), nullptr);
    
    if (result != 1) {
        // Get detailed OpenSSL error
        unsigned long err = ERR_get_error();
        char errBuf[256];
        ERR_error_string_n(err, errBuf, sizeof(errBuf));
        
        EC_POINT_free(peerPoint);
        
        char finalErr[512];
        snprintf(finalErr, sizeof(finalErr), 
                 "Failed to convert binary to EC point (result=%d): %s", 
                 result, errBuf);
        throw std::runtime_error(finalErr);
    }

    // ✅ REST OF EXISTING CODE (lines 167-184)
    int fieldBits = EC_GROUP_get_degree(group);
    int secretLen = (fieldBits + 7) / 8;
    std::vector<unsigned char> sharedSecret(secretLen);
    int ret = ECDH_compute_key(sharedSecret.data(), secretLen, peerPoint, keypair, nullptr);
    EC_POINT_free(peerPoint);
    
    if (ret <= 0) {
        unsigned long err = ERR_get_error();
        char errBuf[256];
        ERR_error_string_n(err, errBuf, sizeof(errBuf));
        
        char finalErr[512];
        snprintf(finalErr, sizeof(finalErr), "ECDH_compute_key failed: %s", errBuf);
        throw std::runtime_error(finalErr);
    }
    
    sharedSecret.resize(ret);

    static const unsigned char saltBytes[] = "MeshChat-v1";
    std::vector<unsigned char> salt(saltBytes, saltBytes + sizeof(saltBytes) - 1);
    std::vector<unsigned char> myPub = getPublicKey();
    std::vector<unsigned char> info = concatSorted(myPub, peerPubKey);

    return hkdfSha256(sharedSecret, salt, info, 32);
}

std::vector<unsigned char> Crypto::encryptAESGCM(
    const std::vector<unsigned char>& key,
    const std::string& plaintext,
    std::vector<unsigned char>& outIV, std::vector<unsigned char>& outTag)
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create cipher context");
    }
    // Generate random IV
    std::vector<unsigned char> iv(12);
    randomBytes(iv);
    // Initialize encryption
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize encryption");
    }
    // Set IV length
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, 12, nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to set IV length");
    }
    // Generate random IV
    outIV.resize(12);
    fillRandom(outIV);
    // Set key and IV
    if (EVP_EncryptInit_ex(ctx, nullptr, nullptr, key.data(), outIV.data()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to set key and IV");
    }
    // Encrypt
    std::vector<unsigned char> ciphertext(plaintext.size() + 16);
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext.data(), &len,
                         reinterpret_cast<const unsigned char*>(plaintext.data()),
                         plaintext.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Encryption failed");
    }
    int ciphertext_len = len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Encryption finalization failed");
    }
    
    ciphertext_len += len;
    ciphertext.resize(ciphertext_len);
    // Finalize
    outTag.resize(16);
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, 16, outTag.data()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to get tag");
    }
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext;
}

std::string Crypto::decryptAESGCM(
    const std::vector<unsigned char>& key,
    const std::vector<unsigned char>& iv,
    const std::vector<unsigned char>& tag,
    const std::vector<unsigned char>& ciphertext)
{
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        throw std::runtime_error("Failed to create cipher context");
    }
    // Initialize decryption
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to initialize decryption");
    }
    // Set IV length
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, iv.size(), nullptr) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to set IV length");
    }
    // Set key and IV
    if (EVP_DecryptInit_ex(ctx, nullptr, nullptr, key.data(), iv.data()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to set key and IV");
    }
    // Decrypt
    std::vector<unsigned char> plaintext(ciphertext.size());
    int len;
    if (EVP_DecryptUpdate(ctx, plaintext.data(), &len, ciphertext.data(), ciphertext.size()) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Decryption failed");
    }
    // Decrypt
    int plaintext_len = len;
    // Set expected tag
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, tag.size(),
                           const_cast<unsigned char*>(tag.data())) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        throw std::runtime_error("Failed to set tag");
    }
    int ret = EVP_DecryptFinal_ex(ctx, plaintext.data() + len, &len);
    EVP_CIPHER_CTX_free(ctx);
    if (ret <= 0) {
        throw std::runtime_error("Decryption failed: authentication tag mismatch");
    }
    
    plaintext_len += len;
    plaintext.resize(plaintext_len);

    return std::string(plaintext.begin(), plaintext.end());
}

Crypto::EncryptedData Crypto::encrypt(const std::string& plaintext, const std::vector<unsigned char>& key) {
    if (key.size() != 32) {
        throw std::runtime_error("Key must be 32 bytes for AES-256");
    }
    
    EncryptedData result;
    result.ciphertext = encryptAESGCM(key, plaintext, result.iv, result.tag);
    return result;
}

std::string Crypto::decrypt(const EncryptedData& encData, const std::vector<unsigned char>& key) {
    if (key.size() != 32) {
        throw std::runtime_error("Key must be 32 bytes for AES-256");
    }
    
    return decryptAESGCM(key, encData.iv, encData.tag, encData.ciphertext);
}