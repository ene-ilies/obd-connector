/*
 * SerialMonitor.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: ilies
 */

#include "SerialMonitor.h"
#include "StandardPIDResponse.h"

SerialMonitor::SerialMonitor(SerialReader *serialReader, SerialEventBus *serialEventBus): stopped(false) {
	this->serialReader = serialReader;
	this->serialEventBus = serialEventBus;
	this->thread = NULL;
}

SerialMonitor::~SerialMonitor() {
	delete serialReader;
	delete thread;
	delete serialEventBus;
}

void SerialMonitor::monitor() {
	this->thread = new boost::thread(&SerialMonitor::monitorLoop, this);
}

void SerialMonitor::stop() {
	stopped = true;
}

void SerialMonitor::join() {
	thread->join();
}

void SerialMonitor::monitorLoop() {
	StandardPIDResponse *standardPidResponse = NULL;
	while (!stopped) {
		standardPidResponse = new StandardPIDResponse();
		standardPidResponse->setCommand(serialReader->readLine());
		standardPidResponse->setResponse(serialReader->readLine());

		serialEventBus->handle(standardPidResponse);

		delete standardPidResponse;
	}
}

