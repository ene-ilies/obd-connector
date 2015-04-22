/*
 * CommandsTriggerer.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#include "CommandsTriggerer.h"
#include "StandardPIDRequest.h"

CommandsTriggerer::CommandsTriggerer(CommandSender<StandardPIDRequest*> *commandSender) : stopped(false) {
	this->commandSender = commandSender;
	this->thread = NULL;
}

CommandsTriggerer::~CommandsTriggerer() {
}

void CommandsTriggerer::trigger() {
	this->thread = new boost::thread(&CommandsTriggerer::triggererLoop, this);
}

void CommandsTriggerer::stop() {
	this->stopped = true;
}

void CommandsTriggerer::join() {
	this->thread->join();
}

void CommandsTriggerer::triggererLoop() {
	StandardPIDRequest *standardPIDRequest = new StandardPIDRequest();
	standardPIDRequest->setPid("0C");
	standardPIDRequest->setMode("01");

	while (!stopped) {
		commandSender->sendCommand(standardPIDRequest);

		sleep(1);
	}

	delete standardPIDRequest;
}
