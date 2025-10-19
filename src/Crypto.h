#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <vector>
#include <openssl/ec.h>

class Crypto {
public:
    struct EncryptedData {
        std::vector<unsigned char> iv;
        std::vector<unsigned char> tag;
        std::vector<unsigned char> ciphertext;
    };

private:
    EC_KEY* keypair;

public:
    Crypto();
    ~Crypto();

    void generateKeyPair();
    std::vector<unsigned char> getPublicKey() const;
    std::vector<unsigned char> deriveSharedKey(const std::vector<unsigned char>& peerPubKey);

    // High-level encrypt/decrypt using symmetric key
    EncryptedData encrypt(const std::string& plaintext, const std::vector<unsigned char>& key);
    std::string decrypt(const EncryptedData& encData, const std::vector<unsigned char>& key);

    // Low-level AES-GCM functions
    std::vector<unsigned char> encryptAESGCM(
        const std::vector<unsigned char>& key,
        const std::string& plaintext,
        std::vector<unsigned char>& outIV,
        std::vector<unsigned char>& outTag
    );

    std::string decryptAESGCM(
        const std::vector<unsigned char>& key,
        const std::vector<unsigned char>& iv,
        const std::vector<unsigned char>& tag,
        const std::vector<unsigned char>& ciphertext
    );
};

#endif