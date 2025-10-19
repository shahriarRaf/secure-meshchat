#ifndef EMERGENCYALERT_H
#define EMERGENCYALERT_H

#include <omnetpp.h>
#include <string>

using namespace omnetpp;

class EmergencyAlert : public cSimpleModule {
  private:
    int alertThreshold;
    int alertCount;

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void finish() override;

  public:
    void sendAlert(const std::string& alertMessage);
};

#endif