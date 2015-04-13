/*
 * StandardPIDSender.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#ifndef STANDARDPIDSENDER_H_
#define STANDARDPIDSENDER_H_

#include <CommandSender.h>
#include "StandardPIDRequest.h"
#include "SerialWriter.h"

/**
 * 	Class responsible of sending standards PIDs to port.
 */
class StandardPIDSender: public CommandSender<StandardPIDRequest*> {
public:
	StandardPIDSender(SerialWriter *serialWriter);
	~StandardPIDSender(){}
	/**
	 * Sends given standard command to port.
	 */
	void sendCommand(StandardPIDRequest* request);
private:
	SerialWriter *serialWriter;

};

#endif /* STANDARDPIDSENDER_H_ */
