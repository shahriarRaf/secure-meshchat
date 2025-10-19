#ifndef MESHNODE_H
#define MESHNODE_H

#include <omnetpp.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include "ChatMessage_m.h"
#include "Crypto.h"

using namespace omnetpp;

class MeshNode : public cSimpleModule {
  private:
    Crypto* crypto;
    bool hasFailed;
    int nodeId;

    std::set<int> neighbors;
    std::map<int, std::vector<unsigned char>> peerPublicKeys;
    std::map<int, std::vector<unsigned char>> derivedSymmetricKeys;
    std::set<int> seenMessages;

    int messagesReceived;
    int successfulDecryptions;
    int failedDecryptions;
    int emergencyAlertsReceived;
    std::vector<double> latencies;

    int messagesSent = 0;  // ✅ ADD THIS
    int maxMessages = 5;   // ✅ ADD THIS

    // timer used to trigger periodic sending
    cMessage* sendMessageTimer = nullptr;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return 2; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

    virtual void sendPublicKeyToNeighbors();
    virtual void handleKeyExchange(ChatMessage *msg);
    virtual void deriveSymmetricKeyForPeer(int peerId);
    virtual void broadcastPublicKey();

    virtual void handleDataMessage(ChatMessage* msg);
    virtual void sendMessage(int destNodeId, const std::string& text);
    virtual void sendBroadcast(const std::string& text);
    virtual void sendEmergencyAlert(const std::string& text);
    virtual void forwardMessage(ChatMessage* msg);
    virtual void simulateFailure();
    void sendTestMessage();

    std::string encryptMessage(const std::string& plaintext, int destinationId,
                               std::string& outIV, std::string& outTag);
    bool decryptMessage(const std::string& ivHex, const std::string& tagHex,
                        const std::string& ctHex, int sourceId, std::string& plaintext);

  public:
    MeshNode();
    virtual ~MeshNode();
};

#endif