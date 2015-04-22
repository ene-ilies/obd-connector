/*
 * CommandsTriggerer.h
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#ifndef COMMANDSTRIGGERER_H_
#define COMMANDSTRIGGERER_H_

#include "CommandSender.h"
#include "StandardPIDRequest.h"
#include "boost/thread/thread.hpp"

class CommandsTriggerer {
public:
	CommandsTriggerer(CommandSender<StandardPIDRequest*> *commandSender);
	virtual ~CommandsTriggerer();
	void trigger();
	void stop();
	void join();
private:
	boost::thread* thread;
	CommandSender<StandardPIDRequest*> *commandSender;
	bool stopped;
	void triggererLoop();
};

#endif /* COMMANDSTRIGGERER_H_ */
