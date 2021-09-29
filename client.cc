/*
 * client.cc
 *
 *  Created on: Sep 29, 2021
 *      Author: user
 */

#include <omnetpp.h>

class client: public cSimpleModule {
    cMessage *msg;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(client);

void client::initialize() {
    EV << "Client initialize \n";

    msg = new cMessage("RTS");

    scheduleAt(simTime() + dblrand(), msg->dup());

    EV << "Client initialize COMPLETE \n";
}

void client::handleMessage(cMessage *msg) {
    EV << "Client handle message initialize \n";

    cModule *target;

    msg = new cMessage("RTS");

    target = getParentModule()->getSubmodule("Server");

    sendDirect(msg, target, "radioIn");
    scheduleAt(simTime() + dblrand(), msg->dup());
}
