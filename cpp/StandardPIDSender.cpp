/*
 * StandardPIDSender.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#include <iostream>
#include "StandardPIDSender.h"

StandardPIDSender::StandardPIDSender(SerialWriter *serialWriter) {
	this->serialWriter = serialWriter;
}

void StandardPIDSender::sendCommand(StandardPIDRequest* request) {
	char format[] = "%02s%02s";
	char* command = (char*) malloc(sizeof(char));
	std::sprintf(command, format, request->getMode().c_str(), request->getPid().c_str());

	serialWriter->writeLine(command);

	std::cout << "Command sent: " << command << std::endl;

	delete command;
}
