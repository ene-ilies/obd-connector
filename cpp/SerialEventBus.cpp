/*
 * SerialEventBus.cpp
 *
 *  Created on: Apr 13, 2015
 *      Author: ilies
 */

#include "SerialEventBus.h"
#include "RPMResponseDecoder.h"
#include "StringToHexTransformer.h"
#include <iostream>
#include <fstream>

SerialEventBus::SerialEventBus() {
}

SerialEventBus::~SerialEventBus() {
}

void SerialEventBus::handle(StandardPIDResponse *standardPidResponse) {
	StringToHexTransformer* stringToHexTransformer = new StringToHexTransformer();
	RPMResponseDecoder decoder(stringToHexTransformer);
	std::ofstream os;
	os.open("monitor.txt", std::ios_base::app);
	os << "Command:" << std::endl;
	os << standardPidResponse->getCommand();
	os << "Response: " << std::endl;
	os << decoder.decode(standardPidResponse->getResponse()) << std::endl;
	os.close();
	delete stringToHexTransformer;
}

