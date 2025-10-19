#include "MeshNode.h"
#include <sstream>
#include <iomanip>

static std::string toHex(const std::vector<unsigned char>& data) {
    std::ostringstream oss;
    oss << std::hex << std::setfill('0');
    for (unsigned char b : data)
        oss << std::setw(2) << static_cast<int>(b);
    return oss.str();
}

static std::vector<unsigned char> fromHex(const std::string& hex) {
    std::vector<unsigned char> bytes;
    
    if (hex.length() % 2 != 0) {
        return bytes;  // Invalid hex string
    }
    
    for (size_t i = 0; i < hex.length(); i += 2) {
        std::string byteStr = hex.substr(i, 2);
        char* end;
        unsigned long byte = strtoul(byteStr.c_str(), &end, 16);
        
        if (end != byteStr.c_str() + 2) {
            bytes.clear();
            return bytes;  // Invalid hex character
        }
        
        bytes.push_back(static_cast<unsigned char>(byte));
    }
    
    return bytes;
}

Define_Module(MeshNode);

MeshNode::MeshNode() : crypto(nullptr), hasFailed(false), nodeId(-1),
                       messagesReceived(0), successfulDecryptions(0), 
                       emergencyAlertsReceived(0), messagesSent(0), maxMessages(5) {
}

MeshNode::~MeshNode() {
    delete crypto;
}

void MeshNode::initialize(int stage)
{
    if (stage == 0) {
        nodeId = getIndex();
        hasFailed = false;
        
        // Initialize crypto
        crypto = new Crypto();
        crypto->generateKeyPair();
        
        EV << "🔧 Initializing Node " << nodeId << " (Stage 0)\n";
        
        // Discover neighbors
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
        
        // Initialize statistics
        messagesReceived = 0;
        successfulDecryptions = 0;
        failedDecryptions = 0;
        emergencyAlertsReceived = 0;
    }
    else if (stage == 1) {
        EV << "🔧 Initializing Node " << nodeId << " (Stage 1)\n";
        
        // Broadcast public key
        sendPublicKeyToNeighbors();
        
        // Schedule test activities
        scheduleAt(simTime() + 1.0, new cMessage("sendTestMessage"));
        scheduleAt(simTime() + 1.5, new cMessage("sendBroadcast"));
        scheduleAt(simTime() + 2.0, new cMessage("sendEmergency"));
        
        if (nodeId == 4) {
            scheduleAt(simTime() + 3.0, new cMessage("simulateFailure"));
        }
    }
}

void MeshNode::broadcastPublicKey() {
    std::vector<unsigned char> pubKey = crypto->getPublicKey();
    EV << "🔑 Node " << nodeId << " broadcast public key (" << pubKey.size() << " bytes)\n";

    ChatMessage* keyMsg = new ChatMessage("keyExchange");
    keyMsg->setMessageId(nodeId * 100000);
    keyMsg->setSourceId(nodeId);
    keyMsg->setDestinationId(-1);
    keyMsg->setTimestamp(simTime().dbl());
    keyMsg->setTtl(par("initialTTL"));
    keyMsg->setIsEncrypted(false);
    keyMsg->setIsEmergency(false);

    // encode pubkey as hex to avoid binary truncation
    std::string pubKeyHex = toHex(pubKey);
    keyMsg->setPayload(pubKeyHex.c_str());

    seenMessages.insert(keyMsg->getMessageId());

    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (g->isConnected()) {
            send(keyMsg->dup(), g);
        }
    }
    delete keyMsg;
}

void MeshNode::sendPublicKeyToNeighbors()
{
    std::vector<unsigned char> pub = crypto->getPublicKey();
    std::string pubHex = toHex(pub);
    
    EV << "📤 Node " << nodeId << " broadcast public key (" << pub.size() << " bytes, hex:" << pubHex.length() << " chars)\n";

    int msgId = nodeId * 100000;  // Unique ID for key exchange
    
    for (int gateIndex = 0; gateIndex < gateSize("gate"); ++gateIndex) {
        cGate* g = gate("gate$o", gateIndex);
        if (g->isConnected()) {
            ChatMessage *msg = new ChatMessage("keyExchange");
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);  // Broadcast
            msg->setIsKeyExchange(true);
            msg->setPayload(pubHex.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            send(msg, g);
        }
    }
}

void MeshNode::handleMessage(cMessage *msg)
{
    if (hasFailed) {
        delete msg;
        return;
    }
    
    if (msg->isSelfMessage()) {
        if (strcmp(msg->getName(), "sendTestMessage") == 0) {
            // Send to a neighbor we have keys for
            if (!derivedSymmetricKeys.empty()) {
                int targetId = derivedSymmetricKeys.begin()->first;
                sendMessage(targetId, "Hello from Node " + std::to_string(nodeId) + " to Node " + std::to_string(targetId) + "!");
            }
        } else if (strcmp(msg->getName(), "sendBroadcast") == 0) {
            sendBroadcast("Broadcast from Node " + std::to_string(nodeId) + "!");
        } else if (strcmp(msg->getName(), "sendEmergency") == 0) {
            sendEmergencyAlert("EMERGENCY from Node " + std::to_string(nodeId) + "!");
        } else if (strcmp(msg->getName(), "simulateFailure") == 0) {
            simulateFailure();
        }
        delete msg;
        return;
    }
    
    ChatMessage* chatMsg = dynamic_cast<ChatMessage*>(msg);
    if (!chatMsg) {
        delete msg;
        return;
    }
    
    int msgId = chatMsg->getMessageId();
    int sourceId = chatMsg->getSourceId();
    
    // Don't process our own messages
    if (sourceId == nodeId) {
        delete msg;
        return;
    }
    
    // Check for key exchange FIRST, before deduplication
    if (chatMsg->isKeyExchange()) {
        handleKeyExchange(chatMsg);
        delete msg;
        return;
    }
    
    // Check if already seen (AFTER key exchange check)
    if (seenMessages.find(msgId) != seenMessages.end()) {
        EV << "🔁 Node " << nodeId << " already saw message " << msgId << " - dropping\n";
        delete msg;
        return;
    }
    
    seenMessages.insert(msgId);
    
    int destId = chatMsg->getDestinationId();
    
    // Process if message is for us or broadcast
    if (destId == nodeId || destId == -1) {
        handleDataMessage(chatMsg);
    }
    
    // If this message is for me, stop here (do not forward)
    if (destId == nodeId) {
        delete msg;
        return;
    }
    
    // Only forward if NOT for me
    forwardMessage(chatMsg);

    delete msg;
}

void MeshNode::handleKeyExchange(ChatMessage *msg)
{
    int senderId = msg->getSourceId();
    std::string pubHex = msg->getPayload();
    
    EV << "📥 Node " << nodeId << " received public key from Node " << senderId 
       << " (hex length: " << pubHex.length() << ")\n";
    
    // Convert hex to binary
    std::vector<unsigned char> peerPub = fromHex(pubHex);
    
    if (peerPub.empty()) {
        EV_ERROR << "❌ Failed to decode hex public key from Node " << senderId << "\n";
        return;
    }
    
    if (peerPub.size() != 65) {
        EV_ERROR << "❌ Invalid public key size from Node " << senderId 
                 << " (expected 65, got " << peerPub.size() << ")\n";
        return;
    }
    
    // Verify it's a valid EC point (starts with 0x04 for uncompressed point)
    if (peerPub[0] != 0x04) {
        EV_ERROR << "❌ Invalid EC point format from Node " << senderId 
                 << " (first byte: 0x" << std::hex << (int)peerPub[0] << std::dec << ")\n";
        return;
    }

    // Store the public key
    peerPublicKeys[senderId] = peerPub;
    
    EV << "🔑 Node " << nodeId << " stored public key for peer " << senderId << "\n";
    
    // Derive symmetric key
    deriveSymmetricKeyForPeer(senderId);
}

void MeshNode::deriveSymmetricKeyForPeer(int peerId) {
    if (derivedSymmetricKeys.count(peerId)) {
        EV << "⚠️ Symmetric key for peer " << peerId << " already exists\n";
        return;
    }
    
    auto it = peerPublicKeys.find(peerId);
    if (it == peerPublicKeys.end()) {
        EV_WARN << "⚠️ No public key stored for peer " << peerId << "\n";
        return;
    }
    
    try {
        EV << "🔐 Node " << nodeId << " deriving key with peer " << peerId 
           << " (pub key size: " << it->second.size() << ")\n";
        
        auto shared = crypto->deriveSharedKey(it->second);
        
        if (shared.empty()) {
            throw std::runtime_error("Derived key is empty");
        }
        
        derivedSymmetricKeys[peerId] = shared;
        
        EV << "🔐 Node " << nodeId << " successfully derived symmetric key with peer " << peerId 
           << " (" << shared.size() << " bytes)\n";
    } catch (const std::exception& e) {
        EV_ERROR << "❌ Key derivation failed for peer " << peerId << ": " << e.what() << "\n";
    }
}

std::string MeshNode::encryptMessage(const std::string& plaintext, int destinationId,
                                      std::string& outIV, std::string& outTag) {
    auto it = derivedSymmetricKeys.find(destinationId);
    if (it == derivedSymmetricKeys.end()) {
        EV_ERROR << "❌ No symmetric key for destination " << destinationId << "\n";
        return "";
    }
    
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
    if (it == derivedSymmetricKeys.end()) {
        EV_ERROR << "❌ No symmetric key for source " << sourceId << "\n";
        return false;
    }
    
    try {
        std::vector<unsigned char> iv = fromHex(ivHex);
        std::vector<unsigned char> tag = fromHex(tagHex);
        std::vector<unsigned char> ct = fromHex(ctHex);
        
        if (iv.empty() || tag.empty() || ct.empty()) {
            EV_ERROR << "❌ Failed to decode hex data\n";
            return false;
        }
        
        Crypto::EncryptedData encData;
        encData.iv = iv;
        encData.tag = tag;
        encData.ciphertext = ct;
        
        plaintext = crypto->decrypt(encData, it->second);
        return true;
    } catch (const std::exception& e) {
        EV_ERROR << "❌ Decryption error: " << e.what() << "\n";
        return false;
    }
}

void MeshNode::sendMessage(int destNodeId, const std::string& text) {
    // Check if we have a symmetric key for this destination
    if (derivedSymmetricKeys.find(destNodeId) == derivedSymmetricKeys.end()) {
        EV_ERROR << "❌ No symmetric key for destination " << destNodeId << "\n";
        return;  // Don't try to encrypt
    }
    
    std::string iv, tag;
    std::string ct = encryptMessage(text, destNodeId, iv, tag);
    
    if (ct.empty()) {
        EV_ERROR << "❌ Encryption failed: No symmetric key available\n";
        return;
    }
    
    EV << "🔒 Node " << nodeId << " encrypted message to Node " << destNodeId 
       << " (CT:" << ct.length() << " IV:" << iv.length() 
       << " TAG:" << tag.length() << ")\n";
    
    int sentCount = 0;
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (g->isConnected()) {
            ChatMessage* msg = new ChatMessage();  // Create NEW message for each gate
            msg->setMessageId(nodeId * 1000000 + intuniform(1, 999999));
            msg->setSourceId(nodeId);
            msg->setDestinationId(destNodeId);
            msg->setIsEncrypted(true);
            msg->setPayload(ct.c_str());
            msg->setIv(iv.c_str());
            msg->setTag(tag.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            send(msg, g);
            sentCount++;
        }
    }
    
    EV << "📤 Node " << nodeId << " sent encrypted message to " << sentCount << " neighbors\n";
}

void MeshNode::sendBroadcast(const std::string& text) {
    EV << "📣 Node " << nodeId << " sending broadcast: \"" << text << "\"\n";
    
    int msgId = nodeId * 1000000 + intuniform(1, 999999);
    int sentCount = 0;
    
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (g->isConnected()) {
            ChatMessage* msg = new ChatMessage();  // Create NEW message for each gate
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);  // Broadcast
            msg->setIsEncrypted(false);
            msg->setIsEmergency(false);
            msg->setPayload(text.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            send(msg, g);
            sentCount++;
        }
    }
    
    EV << "📤 Node " << nodeId << " sent broadcast message " << msgId 
       << " to " << sentCount << " neighbors\n";
}

void MeshNode::sendEmergencyAlert(const std::string& text) {
    EV << "🚨 Node " << nodeId << " sending EMERGENCY ALERT!\n";
    
    int msgId = nodeId * 1000000 + intuniform(1, 999999);
    int sentCount = 0;
    
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (g->isConnected()) {
            ChatMessage* msg = new ChatMessage();  // Create NEW message for each gate
            msg->setMessageId(msgId);
            msg->setSourceId(nodeId);
            msg->setDestinationId(-1);  // Broadcast
            msg->setIsEncrypted(false);
            msg->setIsEmergency(true);
            msg->setPayload(text.c_str());
            msg->setTtl(par("initialTTL"));
            msg->setTimestamp(simTime().dbl());
            
            send(msg, g);
            sentCount++;
        }
    }
    
    EV << "📤 Node " << nodeId << " sent emergency alert " << msgId 
       << " to " << sentCount << " neighbors\n";
}

void MeshNode::handleDataMessage(ChatMessage* msg) {
    messagesReceived++;
    
    double latency = simTime().dbl() - msg->getTimestamp();
    if (latency >= 0) {  // Sanity check
        latencies.push_back(latency);
    }
    
    if (msg->isEmergency()) {  // FIX: use isEmergency() not getIsEmergency()
        emergencyAlertsReceived++;
        EV << "🚨 Node " << nodeId << " received EMERGENCY message " 
           << msg->getMessageId() << " from Node " << msg->getSourceId() << "\n";
    }
    
    if (msg->isEncrypted()) {  // FIX: use isEncrypted() not getIsEncrypted()
        std::string plaintext;
        std::string ivHex = msg->getIv();
        std::string tagHex = msg->getTag();
        std::string ctHex = msg->getPayload();
        int sourceId = msg->getSourceId();
        
        if (decryptMessage(ivHex, tagHex, ctHex, sourceId, plaintext)) {
            successfulDecryptions++;
            EV << "🔓 Node " << nodeId << " decrypted message " << msg->getMessageId() 
               << " from Node " << sourceId << ": \"" << plaintext << "\"\n";
        } else {
            failedDecryptions++;
            EV_ERROR << "❌ Node " << nodeId << " failed to decrypt message " 
                     << msg->getMessageId() << " from Node " << sourceId << "\n";
        }
    } else {
        // Plaintext broadcast
        EV << "📨 Node " << nodeId << " received broadcast message " << msg->getMessageId() 
           << " from Node " << msg->getSourceId() << ": \"" << msg->getPayload() << "\"\n";
    }
}

void MeshNode::forwardMessage(ChatMessage* msg) {
    if (msg->getTtl() <= 1) {
        EV << "⏱️  Message " << msg->getMessageId() << " TTL expired at Node " << nodeId << "\n";
        return;  // Don't delete here - caller will delete
    }
    
    msg->setTtl(msg->getTtl() - 1);
    
    int forwardCount = 0;
    for (int i = 0; i < gateSize("gate"); i++) {
        cGate* g = gate("gate$o", i);
        if (g->isConnected()) {
            send(msg->dup(), g);
            forwardCount++;
        }
    }
    
    EV << "📤 Node " << nodeId << " forwarded message " << msg->getMessageId() 
       << " to " << forwardCount << " neighbors (TTL=" << msg->getTtl() << ")\n";
}

void MeshNode::simulateFailure() {
    hasFailed = true;
    EV << "💀 Node " << nodeId << " has FAILED!\n";
}

void MeshNode::finish() {
    double avgLatency = 0;
    double minLatency = 0;
    double maxLatency = 0;
    
    if (!latencies.empty()) {
        avgLatency = 0;
        for (double lat : latencies) avgLatency += lat;
        avgLatency /= latencies.size();
        minLatency = *std::min_element(latencies.begin(), latencies.end());
        maxLatency = *std::max_element(latencies.begin(), latencies.end());
    }
    
    EV << "\n📊 ========== Node " << nodeId << " Statistics ==========\n";
    EV << "   Messages received: " << messagesReceived << "\n";
    EV << "   Successful decryptions: " << successfulDecryptions << "\n";
    EV << "   Emergency alerts: " << emergencyAlertsReceived << "\n";
    EV << "   Average latency: " << avgLatency << "s\n";
    EV << "   Min latency: " << minLatency << "s\n";
    EV << "   Max latency: " << maxLatency << "s\n";
    EV << "   Node failed: " << (hasFailed ? "YES" : "NO") << "\n";
    EV << "================================================\n\n";
    
    recordScalar("messagesReceived", messagesReceived);
    recordScalar("successfulDecryptions", successfulDecryptions);
    recordScalar("emergencyAlerts", emergencyAlertsReceived);
    recordScalar("avgLatency", avgLatency);
    if (messagesReceived > 0) {
        recordScalar("deliveryRatio", (double)successfulDecryptions / messagesReceived);
    }
}

void MeshNode::sendTestMessage()
{
    if (hasFailed) return;
    
    // ✅ STOP AFTER 5 MESSAGES
    if (messagesSent >= maxMessages) {
        EV << "🛑 Node " << nodeId << " reached message limit\n";
        return;
    }
    
    // Send to a neighbor we have keys for
    if (!derivedSymmetricKeys.empty()) {
        int targetId = derivedSymmetricKeys.begin()->first;
        sendMessage(targetId, "Hello from Node " + std::to_string(nodeId) + " to Node " + std::to_string(targetId) + "!");
    }
    
    messagesSent++;  // ✅ INCREMENT COUNTER
    
    // Schedule next message
    scheduleAt(simTime() + par("messageSendInterval").doubleValue(), sendMessageTimer);
}