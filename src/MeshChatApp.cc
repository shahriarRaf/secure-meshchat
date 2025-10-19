#include "MeshChatApp.h"
#include "ChatMessage_m.h"

Define_Module(MeshChatApp);

void MeshChatApp::initialize() {
    sendInterval = par("sendInterval");
    messageCount = 0;
    
    if (sendInterval > 0) {
        cMessage *timer = new cMessage("sendTimer");
        scheduleAt(simTime() + sendInterval, timer);
    }
}

void MeshChatApp::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        // Send a message
        sendChatMessage();
        
        // Schedule next send
        scheduleAt(simTime() + sendInterval, msg);
    } else {
        // Received a chat message
        ChatMessage *chatMsg = dynamic_cast<ChatMessage*>(msg);
        if (chatMsg) {
            EV << "📨 Received message: " << chatMsg->getPayload() << endl;
            emit(registerSignal("messageReceived"), 1);
        }
        delete msg;
    }
}

void MeshChatApp::sendChatMessage() {
    ChatMessage *msg = new ChatMessage();
    
    messageCount++;
    msg->setMessageId(messageCount);
    msg->setSourceId(getParentModule()->par("nodeId"));
    msg->setDestinationId(-1);  // Broadcast
    msg->setPayload("Hello from MeshChatApp!");
    msg->setTimestamp(simTime().dbl());
    msg->setIsEncrypted(false);
    msg->setIsEmergency(false);
    msg->setTtl(10);
    
    send(msg, "out");
    
    EV << "📤 Sent chat message #" << messageCount << endl;
}

void MeshChatApp::finish() {
    EV << "📊 MeshChatApp sent " << messageCount << " messages" << endl;
}