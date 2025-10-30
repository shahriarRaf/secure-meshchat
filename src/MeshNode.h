#ifndef MESHNODE_H
#define MESHNODE_H

#include <omnetpp.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include "ChatMessage_m.h"
#include "Crypto.h"

using namespace omnetpp;

class MeshNode : public cSimpleModule
{
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

    long messagesSent = 0;
    cMessage* sendMessageTimer = nullptr;
    int maxMessages = 5;

    cOutVector vecMessagesSent;
    cOutVector vecMessagesDelivered;
    cOutVector vecMessagesDropped;
    cOutVector vecDeliveryRatio;
    cMessage *vizTimer = nullptr;
    cMessage* mobilityTimer;
    cMessage* linkFailureTimer;

    long messagesDelivered = 0;
    long messagesDropped = 0;

    double packetLossRate;
    int totalBytesSent;
    int totalBytesReceived;
    
    std::map<int, std::queue<ChatMessage*>> transmissionQueues;
    std::map<int, cMessage*> transmissionEndEvents;

    bool enableMobility;
    double posX, posY;
    double velocityX, velocityY;
    
    cMessage* testMessageTimer = nullptr;
    cMessage* broadcastTimer = nullptr;
    cMessage* emergencyTimer = nullptr;
    
    std::map<int, bool> linkStatus;

  protected:
    virtual void initialize(int stage) override;
    virtual int numInitStages() const override { return 2; }
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

    virtual void sendPublicKeyToNeighbors();
    virtual void handleKeyExchange(ChatMessage *msg);
    virtual void deriveSymmetricKeyForPeer(int peerId);

    virtual void handleDataMessage(ChatMessage* msg);
    virtual void sendMessage(int destNodeId, const std::string& text);
    virtual void sendBroadcast(const std::string& text);
    virtual void sendEmergencyAlert(const std::string& text);
    virtual void forwardMessage(ChatMessage* msg);
    virtual void simulateFailure();
    virtual void sendTestMessage();

    std::string encryptMessage(const std::string& plaintext, int destinationId,
                               std::string& outIV, std::string& outTag);
    bool decryptMessage(const std::string& ivHex, const std::string& tagHex,
                        const std::string& ctHex, int sourceId, std::string& plaintext);

    void vizSendMsg(cMessage *msg, bool encrypted);
    void vizReceiveMsg(cMessage *msg, bool success, bool encrypted);
    void vizMarkFailed();
    
    void sendPacketOnGate(ChatMessage* msg, int gateIndex);
    void handleTransmissionEnd(cMessage* event);
    void processQueue(int gateIndex);

    void updatePosition();
    void checkLinkQuality();
    void simulateLinkFailure();
    void restoreLink(int gateIndex);

    static std::string toHex(const std::vector<unsigned char> &data);
    static std::vector<unsigned char> fromHex(const std::string &hex);
    
  public:
    MeshNode();
    virtual ~MeshNode();
};

#endif