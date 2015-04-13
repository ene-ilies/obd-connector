/*
 * CommandSender.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#ifndef COMMANDSENDER_H_
#define COMMANDSENDER_H_

/**
 * Interface defining methods for sending commands to port.
 */
template <class REQ> class CommandSender {

public:
	virtual ~CommandSender() {}
	virtual void sendCommand(REQ request) = 0;

};

#endif /* COMMANDSENDER_H_ */
