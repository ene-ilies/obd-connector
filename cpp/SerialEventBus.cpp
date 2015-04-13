/*
 * SerialEventBus.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: ilies
 */

#include "SerialEventBus.h"
#include <iostream>

SerialEventBus::SerialEventBus() {
}

SerialEventBus::~SerialEventBus() {
}

void SerialEventBus::handle(StandardPIDResponse *standardPidResponse) {
	std::cout << "Command:" << std::endl;
	std::cout << standardPidResponse->getCommand();
	std::cout << "Response: " << std::endl;
	std::cout << standardPidResponse->getResponse();
}

