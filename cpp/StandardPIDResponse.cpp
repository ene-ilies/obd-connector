/*
 * StandardPIDResponse.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#include "StandardPIDResponse.h"
#include <stdlib.h>

StandardPIDResponse::StandardPIDResponse() {
}

StandardPIDResponse::~StandardPIDResponse() {
}

std::string StandardPIDResponse::getCommand() {
	return command;
}

void StandardPIDResponse::setCommand(std::string command) {
	this->command = command;
}

std::string StandardPIDResponse::getResponse() {
	return response;
}

void StandardPIDResponse::setResponse(std::string response) {
	this->response = response;
}


