/*
 * server.cc
 *
 *  Created on: Sep 29, 2021
 *      Author: user
 */

#include <omnetpp.h>

class server: public cSimpleModule {
    cMessage *msg;

    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

Define_Module(server);

void server::initialize() {

}

void server::handleMessage(cMessage *msg) {
    msg = new cMessage("CTS");

    cModule *target = getParentModule()->getSubmodule("Client");

    sendDirect(msg, target, "radioIn");
}
