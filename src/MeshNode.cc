#include "MeshNode.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace omnetpp;

Define_Module(MeshNode);

MeshNode::MeshNode()
{
    crypto = nullptr;
    vizTimer = nullptr;
    sendMessageTimer = nullptr;
    mobilityTimer = nullptr;
    linkFailureTimer = nullptr;
    
    // ✅ ADD THESE:
    testMessageTimer = nullptr;
    broadcastTimer = nullptr;
    emergencyTimer = nullptr;
}

MeshNode::~MeshNode()
{
    delete crypto;
    cancelAndDelete(vizTimer);
    cancelAndDelete(sendMessageTimer);
    cancelAndDelete(mobilityTimer);
    cancelAndDelete(linkFailureTimer);
    
    // ✅ ADD THESE:
    cancelAndDelete(testMessageTimer);
    cancelAndDelete(broadcastTimer);
    cancelAndDelete(emergencyTimer);
}

std::string MeshNode::toHex(const std::vector<unsigned char> &data)
{
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (unsigned char b : data) {
        oss << std::setw(2) << static_cast<int>(b);
    }
    return oss.str();
}

std::vector<unsigned char> MeshNode::fromHex(const std::string &hex)
{
    std::vector<unsigned char> out;
    if (hex.size() % 2 != 0) return out;
    out.reserve(hex.size() / 2);
    for (size_t i = 0; i < hex.size(); i += 2) {
        std::string byteStr = hex.substr(i, 2);
        unsigned int byte = 0;
        std::istringstream iss(byteStr);
        iss >> std::hex >> byte;
        out.push_back(static_cast<unsigned char>(byte));
    }
    return out;
}

void MeshNode::initialize(int stage)
{
    if (stage == 0) {
        nodeId = getIndex();
        hasFailed = false;
        
        packetLossRate = par("packetLossRate").doubleValue();
        totalBytesSent = 0;
        totalBytesReceived = 0;
        
        crypto = new Crypto();
        crypto->generateKeyPair();
        
        enableMobility = par("enableMobility").boolValue();
        mobilityTimer = nullptr;
        linkFailureTimer = nullptr;
        
        if (enableMobility) {
            posX = uniform(0, par("areaWidth").doubleValue());
            posY = uniform(0, par("areaHeight").doubleValue());
            
            double speed = par("mobilitySpeed").doubleValue();
            double angle = uniform(0, 2 * M_PI);
            velocityX = speed * cos(angle);
            velocityY = speed * sin(angle);
            
            mobilityTimer = new cMessage("mobilityUpdate");
            scheduleAt(simTime() + par("mobilityUpdateInterval").doubleValue(), mobilityTimer);
            
            EV << "🚶 Node " << nodeId << " mobility enabled at (" << posX << ", " << posY << ")\n";
        }
        
        for (int i = 0; i < gateSize("gate"); i++) {
            transmissionQueues[i] = std::queue<ChatMessage*>();
            transmissionEndEvents[i] = nullptr;
            linkStatus[i] = true;
        }
        
        linkFailureTimer = new cMessage("linkFailure");
        scheduleAt(simTime() + exponential(50.0), linkFailureTimer);
        
        EV << "🔧 Initializing Node " << nodeId << " (Stage 0)\n";
        
        for (int i = 0; i < gateSize("gate"); i++) {
            cGate* g = gate("gate$o", i);
            if (g->isConnected()) {
                cGate* nextGate = g->getNextGate();
                int neighborId = nextGate->getOwnerModule()->getIndex();
                neighbors.insert(neighborId);
                EV << "  🔗  Node " << nodeId << " connected to Node " << neighborId << "\n";
            }
        }
        
        EV << "🔐 Node " << nodeId << " generated cryptographic keys\n";
        
        messagesReceived = 0;
        successfulDecryptions = 0;
        failedDecryptions = 0;
        emergencyAlertsReceived = 0;
    }
    else if (stage == 1) {
        EV << "🔧 Initializing Node " << nodeId << " (Stage 1)\n";
        
        sendPublicKeyToNeighbors();
        
        // ✅ CHANGED: Store timer references
        testMessageTimer = new cMessage("sendTestMessage");
        broadcastTimer = new cMessage("sendBroadcast");
        emergencyTimer = new cMessage("sendEmergency");
        
        scheduleAt(simTime() + 0.5, testMessageTimer);
        scheduleAt(simTime() + 1.0, broadcastTimer);
        scheduleAt(simTime() + 2.0, emergencyTimer);
        
        if (nodeId == 3 || nodeId == 7) {
            double failTime = (nodeId == 3) ? 5.0 : 15.0;
            EV << "\n";
            EV << "⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️\n";
            EV << "⏰ Node " << nodeId << " scheduled to FAIL at t=" << failTime << "s\n";
            EV << "⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️⚠️\n";
            EV << "\n";
            scheduleAt(simTime() + failTime, new cMessage("simulateFailure"));
        }
        
        vecMessagesSent.setName("messagesSent");
        vecMessagesDelivered.setName("messagesDelivered");
        vecMessagesDropped.setName("messagesDropped");
        vecDeliveryRatio.setName("deliveryRatio");

        if (!vizTimer) {
            vizTimer = new cMessage("vizTimer");
            scheduleAt(simTime() + 0.5, vizTimer);
        }
    }
}

void MeshNode::handleMessage(cMessage *msg)
{    
    // Handle transmission end events
    if (msg->isSelfMessage() && strstr(msg->getName(), "transmissionEnd") != nullptr) {
        handleTransmissionEnd(msg);
        return;
    }
    
    // Handle mobility timer
    if (msg == mobilityTimer) {
        if (!hasFailed) {
            updatePosition();
        }
        scheduleAt(simTime() + par("mobilityUpdateInterval").doubleValue(), mobilityTimer);
        return;
    }
    
    // Handle link failure timer
    if (msg == linkFailureTimer) {
        if (!hasFailed) {
            simulateLinkFailure();
        }
        scheduleAt(simTime() + exponential(50.0), linkFailureTimer);
        return;
    }
    
    // Handle link restoration
    if (msg->isSelfMessage() && strcmp(msg->getName(), "restoreLink") == 0) {
        int gateIndex = (int)(intptr_t)msg->getContextPointer();
        restoreLink(gateIndex);
        delete msg;
        return;
    }
    
    // Handle visualization timer
    if (msg == vizTimer) {
        if (!hasFailed) {
            vecMessagesSent.record(messagesSent);
            vecMessagesDelivered.record(messagesDelivered);
            vecMessagesDropped.record(messagesDropped);
            double ratio = (messagesSent>0) ? (double)messagesDelivered / messagesSent : 0.0;
            vecDeliveryRatio.record(ratio);
        }
        scheduleAt(simTime() + 0.5, vizTimer);
        return;
    }

    // ✅ CHECK 1: Block self-messages if failed
    if (hasFailed && msg->isSelfMessage()) {
        EV << "🚫 Node " << nodeId << " FAILED - dropping self-message: " << msg->getName() << "\n";
        
        // Don't delete reusable timer messages
        if (msg != testMessageTimer && 
            msg != broadcastTimer && 
            msg != emergencyTimer &&
            msg != vizTimer &&
            msg != mobilityTimer &&
            msg != linkFailureTimer) {
            delete msg;
        }
        return;
    }
    
    // Process self-messages (only if not failed)
    if (msg->isSelfMessage()) {
        if (msg == testMessageTimer) {
            sendTestMessage();
            return;
        } 
        else if (msg == broadcastTimer) {
            sendBroadcast("Broadcast from Node " + std::to_string(nodeId) + "!");
            return;
        } 
        else if (msg == emergencyTimer) {
            sendEmergencyAlert("EMERGENCY from Node " + std::to_string(nodeId) + "!");
            return;
        } 
        else if (strcmp(msg->getName(), "simulateFailure") == 0) {
            simulateFailure();
            delete msg;
            return;
        }
        
        delete msg;
        return;
    }
    
    // ✅ CHECK 2: Block ALL incoming messages if failed (NEW!)
    if (hasFailed) {
        ChatMessage* chatMsg = dynamic_cast<ChatMessage*>(msg);
        if (chatMsg) {
            EV << "🚫 Node " << nodeId << " FAILED - dropping incoming message from Node " 
               << chatMsg->getSourceId() << " (msgId=" << chatMsg->getMessageId() << ")\n";
        } else {
            EV << "🚫 Node " << nodeId << " FAILED - dropping incoming message: " << msg->getName() << "\n";
        }
        delete msg;
        return;
    }
    
    // ✅ Process incoming ChatMessage (only if NOT failed)
    ChatMessage* chatMsg = dynamic_cast<ChatMessage*>(msg);
    if (!chatMsg) {
        delete msg;
        return;
    }
    
    int msgId = chatMsg->getMessageId();
    int sourceId = chatMsg->getSourceId();
    
    if (sourceId == nodeId) {
        delete msg;
        return;
    }
    
    if (chatMsg->isKeyExchange()) {
        handleKeyExchange(chatMsg);
        delete msg;
        return;
    }
    
    if (seenMessages.find(msgId) != seenMessages.end()) {
        EV << "🔁 Node " << nodeId << " already saw message " << msgId << " - dropping\n";
        delete msg;
        return;
    }
    
    seenMessages.insert(msgId);
    
    int destId = chatMsg->getDestinationId();
    
    if (destId == nodeId || destId == -1) {
        handleDataMessage(chatMsg);
    }
    
    if (destId == nodeId) {
        delete msg;
        return;
    }
    
    forwardMessage(chatMsg);
    delete msg;
}

void MeshNode::sendPublicKeyToNeighbors()
{
    std::vector<unsigned char> pub = crypto->getPublicKey();
    std::string pubHex = toHex(pub);
    
    EV << "📤 Node " << nodeId << " broadcast public key (" << pub.size() << " bytes, hex:" << pubHex.length() << " chars)\n";

    int msgId = nodeId * 100000;
    
    for (int gateIndex = 0; gateIndex < gateSize("gate"); ++gateIndex) {
        cGate* g = gate("gate$o", gateIndex);
        if (g->isConnected()) {
            ChatMessage *msg = new ChatMessage("keyExchange");
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);
            msg->setIsKeyExchange(true);
            msg->setPayload(pubHex.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            send(msg, g);
        }
    }
}

void MeshNode::handleKeyExchange(ChatMessage *msg)
{
    int senderId = msg->getSourceId();
    std::string pubHex = msg->getPayload();
    
    EV << "📥 Node " << nodeId << " received public key from Node " << senderId 
       << " (hex length: " << pubHex.length() << ")\n";
    
    std::vector<unsigned char> peerPub = fromHex(pubHex);
    
    if (peerPub.empty() || peerPub.size() != 65 || peerPub[0] != 0x04) {
        EV_ERROR << "❌ Invalid public key from Node " << senderId << "\n";
        return;
    }

    peerPublicKeys[senderId] = peerPub;
    EV << "🔑 Node " << nodeId << " stored public key for peer " << senderId << "\n";
    
    deriveSymmetricKeyForPeer(senderId);
}

void MeshNode::deriveSymmetricKeyForPeer(int peerId) {
    if (derivedSymmetricKeys.count(peerId)) return;
    
    auto it = peerPublicKeys.find(peerId);
    if (it == peerPublicKeys.end()) return;
    
    try {
        EV << "🔐 Node " << nodeId << " deriving key with peer " << peerId << "\n";
        auto shared = crypto->deriveSharedKey(it->second);
        derivedSymmetricKeys[peerId] = shared;
        EV << "🔐 Node " << nodeId << " successfully derived symmetric key with peer " << peerId << "\n";
    } catch (const std::exception& e) {
        EV_ERROR << "❌ Key derivation failed: " << e.what() << "\n";
    }
}

std::string MeshNode::encryptMessage(const std::string& plaintext, int destinationId,
                                      std::string& outIV, std::string& outTag) {
    auto it = derivedSymmetricKeys.find(destinationId);
    if (it == derivedSymmetricKeys.end()) return "";
    
    try {
        auto result = crypto->encrypt(plaintext, it->second);
        outIV = toHex(result.iv);
        outTag = toHex(result.tag);
        return toHex(result.ciphertext);
    } catch (const std::exception& e) {
        EV_ERROR << "❌ Encryption error: " << e.what() << "\n";
        return "";
    }
}

bool MeshNode::decryptMessage(const std::string& ivHex, const std::string& tagHex,
                               const std::string& ctHex, int sourceId, std::string& plaintext) {
    auto it = derivedSymmetricKeys.find(sourceId);
    if (it == derivedSymmetricKeys.end()) return false;
    
    try {
        Crypto::EncryptedData encData;
        encData.iv = fromHex(ivHex);
        encData.tag = fromHex(tagHex);
        encData.ciphertext = fromHex(ctHex);
        
        plaintext = crypto->decrypt(encData, it->second);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}

void MeshNode::sendMessage(int destNodeId, const std::string& text) {
    if (derivedSymmetricKeys.find(destNodeId) == derivedSymmetricKeys.end()) return;
    
    std::string iv, tag;
    std::string ct = encryptMessage(text, destNodeId, iv, tag);
    if (ct.empty()) return;
    
    EV << "🔒 Node " << nodeId << " encrypted message to Node " << destNodeId << "\n";
    
    for (int i = 0; i < gateSize("gate"); i++) {
        if (gate("gate$o", i)->isConnected()) {
            ChatMessage* msg = new ChatMessage();
            msg->setMessageId(nodeId * 1000000 + intuniform(1, 999999));
            msg->setSourceId(nodeId);
            msg->setDestinationId(destNodeId);
            msg->setIsEncrypted(true);
            msg->setPayload(ct.c_str());
            msg->setIv(iv.c_str());
            msg->setTag(tag.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            sendPacketOnGate(msg, i);
            totalBytesSent += msg->getByteLength();
            messagesSent++;
        }
    }
}

void MeshNode::sendBroadcast(const std::string& text) {
    int msgId = nodeId * 1000000 + intuniform(1, 999999);
    
    for (int i = 0; i < gateSize("gate"); i++) {
        if (gate("gate$o", i)->isConnected()) {
            ChatMessage* msg = new ChatMessage();
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);
            msg->setIsEncrypted(false);
            msg->setIsEmergency(false);
            msg->setPayload(text.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            sendPacketOnGate(msg, i);
        }
    }
}

void MeshNode::sendEmergencyAlert(const std::string& text) {
    EV << "🚨 Node " << nodeId << " sending EMERGENCY ALERT!\n";
    
    int msgId = nodeId * 1000000 + intuniform(1, 999999);
    
    for (int i = 0; i < gateSize("gate"); i++) {
        if (gate("gate$o", i)->isConnected()) {
            ChatMessage* msg = new ChatMessage();
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);
            msg->setIsEncrypted(false);
            msg->setIsEmergency(true);
            msg->setPayload(text.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            sendPacketOnGate(msg, i);
        }
    }
}

void MeshNode::handleDataMessage(ChatMessage* msg) {
    messagesReceived++;
    totalBytesReceived += msg->getByteLength();
    
    double latency = simTime().dbl() - msg->getTimestamp();
    if (latency >= 0) {
        latencies.push_back(latency);
        EV << "⏱️  Latency: " << latency << "s\n";
    }
    
    if (msg->isEmergency()) {
        emergencyAlertsReceived++;
        EV << "🚨 Node " << nodeId << " received EMERGENCY\n";
    }
    
    if (msg->isEncrypted()) {
        std::string plaintext;
        if (decryptMessage(msg->getIv(), msg->getTag(), msg->getPayload(), msg->getSourceId(), plaintext)) {
            successfulDecryptions++;
            EV << "🔓 Node " << nodeId << " decrypted message: \"" << plaintext << "\"\n";
        } else {
            failedDecryptions++;
        }
    }
}

void MeshNode::forwardMessage(ChatMessage* msg) {
    if (msg->getTtl() <= 1) return;
    
    msg->setTtl(msg->getTtl() - 1);
    
    int forwardCount = 0;
    
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        
        // ✅ Check link status
        if (!g->isConnected() || !linkStatus[i]) {
            EV << "📡 Skip gate " << i << " (link down)\n";
            continue;
        }
        
        if (uniform(0, 1) < packetLossRate) {
            messagesDropped++;
            continue;
        }
        
        ChatMessage* fwdMsg = msg->dup();
        sendPacketOnGate(fwdMsg, i);
        totalBytesSent += fwdMsg->getByteLength();
        messagesSent++;
        forwardCount++;
    }
}

void MeshNode::sendTestMessage() {
    if (!derivedSymmetricKeys.empty()) {
        int targetId = derivedSymmetricKeys.begin()->first;
        sendMessage(targetId, "Hello from Node " + std::to_string(nodeId) + "!");
    }
}

// ✅ NEW MOBILITY & LINK FAILURE FUNCTIONS:

void MeshNode::updatePosition() {
    double dt = par("mobilityUpdateInterval").doubleValue();
    
    posX += velocityX * dt;
    posY += velocityY * dt;
    
    double areaWidth = par("areaWidth").doubleValue();
    double areaHeight = par("areaHeight").doubleValue();
    
    if (posX < 0 || posX > areaWidth) {
        velocityX = -velocityX;
        posX = std::max(0.0, std::min(posX, areaWidth));
    }
    
    if (posY < 0 || posY > areaHeight) {
        velocityY = -velocityY;
        posY = std::max(0.0, std::min(posY, areaHeight));
    }
    
    getDisplayString().setTagArg("p", 0, (int)posX);
    getDisplayString().setTagArg("p", 1, (int)posY);
    
    checkLinkQuality();
}

void MeshNode::checkLinkQuality() {
    double radioRange = 300.0;
    
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (!g->isConnected()) continue;
        
        cGate* neighborGate = g->getNextGate();
        if (!neighborGate) continue;
        
        MeshNode* neighbor = dynamic_cast<MeshNode*>(neighborGate->getOwnerModule());
        if (!neighbor || !neighbor->par("enableMobility").boolValue()) continue;
        
        double dx = posX - neighbor->posX;
        double dy = posY - neighbor->posY;
        double distance = sqrt(dx*dx + dy*dy);
        
        if (distance > radioRange && linkStatus[i]) {
            EV << "📡 LINK DOWN on gate " << i << " (distance: " << distance << "m)\n";
            linkStatus[i] = false;
            g->getDisplayString().setTagArg("ls", 0, "red");
        } else if (distance <= radioRange && !linkStatus[i]) {
            EV << "📡 LINK UP on gate " << i << "\n";
            linkStatus[i] = true;
            g->getDisplayString().setTagArg("ls", 0, "");
        }
    }
}

void MeshNode::simulateLinkFailure() {
    if (gateSize("gate") == 0) return;
    
    int gateIndex = intuniform(0, gateSize("gate") - 1);
    cGate* g = gate("gate$o", gateIndex);
    
    if (!g->isConnected() || !linkStatus[gateIndex]) return;
    
    linkStatus[gateIndex] = false;
    g->getDisplayString().setTagArg("ls", 0, "red");
    
    EV << "💥 LINK FAILED on gate " << gateIndex << "\n";
    
    cMessage* restoreMsg = new cMessage("restoreLink");
    restoreMsg->setContextPointer((void*)(intptr_t)gateIndex);
    scheduleAt(simTime() + uniform(10.0, 30.0), restoreMsg);
}

void MeshNode::restoreLink(int gateIndex) {
    if (gateIndex >= gateSize("gate")) return;
    
    cGate* g = gate("gate$o", gateIndex);
    if (!g->isConnected()) return;
    
    linkStatus[gateIndex] = true;
    g->getDisplayString().setTagArg("ls", 0, "");
    
    EV << "✅ LINK RESTORED on gate " << gateIndex << "\n";
}

void MeshNode::sendPacketOnGate(ChatMessage* msg, int gateIndex)
{
    cGate* outGate = gate("gate$o", gateIndex);
    cChannel* channel = outGate->getTransmissionChannel();
    
    if (channel == nullptr) {
        send(msg, outGate);
        return;
    }
    
    simtime_t finishTime = channel->getTransmissionFinishTime();
    
    if (finishTime > simTime()) {
        transmissionQueues[gateIndex].push(msg);
    } else {
        send(msg, outGate);
        
        simtime_t txFinish = simTime() + channel->calculateDuration(msg);
        
        if (transmissionEndEvents[gateIndex] != nullptr) {
            cancelEvent(transmissionEndEvents[gateIndex]);
        }
        
        cMessage* endEvent = new cMessage("transmissionEnd");
        endEvent->setContextPointer((void*)(intptr_t)gateIndex);
        transmissionEndEvents[gateIndex] = endEvent;
        scheduleAt(txFinish, endEvent);
    }
}

void MeshNode::handleTransmissionEnd(cMessage* event)
{
    int gateIndex = (int)(intptr_t)event->getContextPointer();
    transmissionEndEvents[gateIndex] = nullptr;
    delete event;
    processQueue(gateIndex);
}

void MeshNode::processQueue(int gateIndex)
{
    if (transmissionQueues[gateIndex].empty()) return;
    
    ChatMessage* msg = transmissionQueues[gateIndex].front();
    transmissionQueues[gateIndex].pop();
    sendPacketOnGate(msg, gateIndex);
}

void MeshNode::simulateFailure() {
    hasFailed = true;
    
    EV << "\n";
    EV << "💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀\n";
    EV << "💀 NODE " << nodeId << " COMPLETE FAILURE at t=" << simTime() << "s\n";
    EV << "💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀💀\n";
    EV << "\n";
    
    // ✅ Cancel ALL timers
    if (vizTimer && vizTimer->isScheduled()) {
        cancelEvent(vizTimer);
        EV << "   ✓ Canceled vizTimer\n";
    }
    if (mobilityTimer && mobilityTimer->isScheduled()) {
        cancelEvent(mobilityTimer);
        EV << "   ✓ Canceled mobilityTimer\n";
    }
    if (linkFailureTimer && linkFailureTimer->isScheduled()) {
        cancelEvent(linkFailureTimer);
        EV << "   ✓ Canceled linkFailureTimer\n";
    }
    
    // ✅ ADD: Cancel message sending timers
    if (testMessageTimer && testMessageTimer->isScheduled()) {
        cancelEvent(testMessageTimer);
        EV << "   ✓ Canceled testMessageTimer\n";
    }
    if (broadcastTimer && broadcastTimer->isScheduled()) {
        cancelEvent(broadcastTimer);
        EV << "   ✓ Canceled broadcastTimer\n";
    }
    if (emergencyTimer && emergencyTimer->isScheduled()) {
        cancelEvent(emergencyTimer);
        EV << "   ✓ Canceled emergencyTimer\n";
    }
    
    // Clear all queues
    int queuedMessages = 0;
    for (auto& queue : transmissionQueues) {
        while (!queue.second.empty()) {
            delete queue.second.front();
            queue.second.pop();
            queuedMessages++;
        }
    }
    if (queuedMessages > 0) {
        EV << "   ✓ Cleared " << queuedMessages << " queued messages\n";
    }
    
    // Cancel transmission events
    for (auto& event : transmissionEndEvents) {
        if (event.second && event.second->isScheduled()) {
            cancelEvent(event.second);
        }
    }
    
    vizMarkFailed();
    
    EV << "🚫 Node " << nodeId << " ALL OPERATIONS TERMINATED\n";
    EV << "================================================\n\n";
}

void MeshNode::vizMarkFailed()
{
    getDisplayString().setTagArg("i", 1, "red");
    bubble("❌ FAILED");
}

void MeshNode::finish()
{
    if (vizTimer) {
        cancelAndDelete(vizTimer);
        vizTimer = nullptr;
    }

    double avgLatency = 0, minLatency = 0, maxLatency = 0;
    if (!latencies.empty()) {
        for (double lat : latencies) avgLatency += lat;
        avgLatency /= latencies.size();
        minLatency = *std::min_element(latencies.begin(), latencies.end());
        maxLatency = *std::max_element(latencies.begin(), latencies.end());
    }
    
    double overhead = (totalBytesReceived > 0) ? ((double)totalBytesSent / totalBytesReceived) - 1.0 : 0.0;
    double actualLossRate = (messagesSent > 0) ? (double)messagesDropped / messagesSent : 0.0;
    
    EV << "\n📊 ========== Node " << nodeId << " Statistics ==========\n";
    EV << "   Messages sent: " << messagesSent << "\n";
    EV << "   Messages received: " << messagesReceived << "\n";
    EV << "   Packet loss rate: " << (actualLossRate * 100) << "%\n";
    EV << "   Network overhead: " << (overhead * 100) << "%\n";
    EV << "   Successful decryptions: " << successfulDecryptions << "\n";
    EV << "   Average latency: " << avgLatency << "s\n";
    EV << "================================================\n\n";
}