#include "EncryptionModule.h"
#include "ChatMessage_m.h"
#include <stdexcept>

Define_Module(EncryptionModule);

EncryptionModule::EncryptionModule() : crypto(nullptr) {
}

EncryptionModule::~EncryptionModule() {
    delete crypto;
}

void EncryptionModule::initialize() {
    try {
        crypto = new Crypto();
        crypto->generateKeyPair();
        EV << "✅ EncryptionModule initialized with crypto engine\n";
    } catch (const std::exception& e) {
        EV_ERROR << "❌ Failed to initialize crypto: " << e.what() << "\n";
        crypto = nullptr;
    }
}

void EncryptionModule::handleMessage(cMessage *msg) {
    // EncryptionModule doesn't receive messages directly
    // It's used as a helper by other modules
    delete msg;
}

void EncryptionModule::finish() {
    EV << "EncryptionModule finishing\n";
}

std::string EncryptionModule::encrypt(const std::string& plaintext, int peerId) {
    if (!crypto) {
        throw std::runtime_error("Crypto not initialized");
    }
    
    try {
        // For now, return base64-encoded plaintext as placeholder
        // Real implementation would derive shared key with peerId and encrypt
        std::vector<unsigned char> iv, tag;
        std::vector<unsigned char> dummyKey(32, 0xAB); // placeholder key
        
        std::vector<unsigned char> ciphertext = crypto->encryptAESGCM(
            dummyKey, plaintext, iv, tag
        );
        
        // Combine IV + tag + ciphertext
        std::string result;
        result.append(reinterpret_cast<const char*>(iv.data()), iv.size());
        result.append(reinterpret_cast<const char*>(tag.data()), tag.size());
        result.append(reinterpret_cast<const char*>(ciphertext.data()), ciphertext.size());
        
        return result;
    } catch (const std::exception& e) {
        EV_ERROR << "Encryption failed: " << e.what() << "\n";
        throw;
    }
}

bool EncryptionModule::decrypt(const std::string& iv, const std::string& tag,
                               const std::string& ciphertext, int peerId,
                               std::string& plaintext) {
    if (!crypto) {
        return false;
    }
    
    try {
        std::vector<unsigned char> ivVec(iv.begin(), iv.end());
        std::vector<unsigned char> tagVec(tag.begin(), tag.end());
        std::vector<unsigned char> ctVec(ciphertext.begin(), ciphertext.end());
        std::vector<unsigned char> dummyKey(32, 0xAB); // placeholder
        
        plaintext = crypto->decryptAESGCM(dummyKey, ivVec, tagVec, ctVec);
        return true;
    } catch (const std::exception& e) {
        EV_WARN << "Decryption failed: " << e.what() << "\n";
        return false;
    }
}