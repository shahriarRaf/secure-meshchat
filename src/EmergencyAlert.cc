#include "EmergencyAlert.h"
#include "ChatMessage_m.h"

Define_Module(EmergencyAlert);

void EmergencyAlert::initialize() {
    alertThreshold = par("alertThreshold");
    alertCount = 0;
}

void EmergencyAlert::handleMessage(cMessage *msg) {
    ChatMessage *chatMsg = dynamic_cast<ChatMessage*>(msg);
    
    if (chatMsg) {
        if (chatMsg->isEmergency()) {
            alertCount++;
            EV << "🚨 EMERGENCY ALERT #" << alertCount << " received!" << endl;
            EV << "   Message: " << chatMsg->getPayload() << endl;
            emit(registerSignal("emergencyAlertReceived"), alertCount);
        }
    }
    
    delete msg;
}

void EmergencyAlert::sendAlert(const std::string& alertMessage) {
    if (gate("out")->isConnected()) {
        ChatMessage *alertMsg = new ChatMessage();
        
        alertMsg->setMessageId(intuniform(1, 999999));
        alertMsg->setSourceId(0);
        alertMsg->setDestinationId(-1);
        alertMsg->setPayload(alertMessage.c_str());
        alertMsg->setTimestamp(simTime().dbl());
        alertMsg->setIsEmergency(true);
        alertMsg->setIsEncrypted(false);
        alertMsg->setTtl(10);
        
        send(alertMsg, "out");
        
        EV << "📤 Emergency alert sent: " << alertMessage << endl;
    }
}

void EmergencyAlert::finish() {
    EV << "📊 Total emergency alerts received: " << alertCount << endl;
}