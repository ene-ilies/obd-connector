/*
 * SerialMonitor.cpp
 *
 *  Created on: Apr 12, 2015
 *      Author: ilies
 */

#include "SerialMonitor.h"
#include "StandardPIDResponse.h"
#include <iostream>

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
		std::string s = serialReader->readLine();
		std::cout << s;

		standardPidResponse->setCommand(s);
		s = serialReader->readLine();
		std::cout << s;
		standardPidResponse->setResponse(s);

		serialEventBus->handle(standardPidResponse);

		delete standardPidResponse;
	}
}

