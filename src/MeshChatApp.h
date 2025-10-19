#ifndef MESHCHATAPP_H
#define MESHCHATAPP_H

#include <omnetpp.h>
#include <string>

using namespace omnetpp;

class MeshChatApp : public cSimpleModule {
private:
    double sendInterval;
    int messageCount;

protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;
    
    void sendChatMessage();
};

#endif