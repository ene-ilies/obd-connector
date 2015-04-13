/*
 * SerialMonitor.h
 *
 *  Created on: Apr 12, 2015
 *      Author: ilies
 */

#ifndef SERIALMONITOR_H_
#define SERIALMONITOR_H_

#include <boost/thread/thread.hpp>
#include "SerialReader.h"
#include "SerialEventBus.h"

class SerialMonitor {
public:
	SerialMonitor(SerialReader *serialReader, SerialEventBus *serialEventBus);
	virtual ~SerialMonitor();
	void monitor();
	void stop();
	void join();
private:
	SerialEventBus *serialEventBus;
	boost::thread* thread;
	SerialReader *serialReader;
	bool stopped;
	void monitorLoop();
};

#endif /* SERIALMONITOR_H_ */
