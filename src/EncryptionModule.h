#ifndef ENCRYPTIONMODULE_H
#define ENCRYPTIONMODULE_H

#include <omnetpp.h>
#include "Crypto.h"

using namespace omnetpp;

class EncryptionModule : public cSimpleModule {
private:
    Crypto* crypto;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

public:
    EncryptionModule();
    virtual ~EncryptionModule();
    
    std::string encrypt(const std::string& plaintext, int peerId);
    bool decrypt(const std::string& iv, const std::string& tag, 
                 const std::string& ciphertext, int peerId, std::string& plaintext);
};

#endif