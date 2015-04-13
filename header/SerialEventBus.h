/*
 * SerialEventBus.h
 *
 *  Created on: Apr 13, 2015
 *      Author: ilies
 */

#ifndef SERIALEVENTBUS_H_
#define SERIALEVENTBUS_H_

#include "StandardPIDResponse.h"

class SerialEventBus {
public:
	SerialEventBus();
	virtual ~SerialEventBus();
	void handle(StandardPIDResponse *standardPidResponse);
};

#endif /* SERIALEVENTBUS_H_ */
