/*
 * SerialWriter.h
 *
 *  Created on: Apr 8, 2015
 *      Author: ilies
 */

#ifndef SERIALWRITER_H_
#define SERIALWRITER_H_

#include <boost/asio.hpp>
#include <iostream>

class SerialWriter {
public:
	static const char EOL;
	SerialWriter(boost::asio::serial_port *port);
	~SerialWriter();
	void writeLine(std::string line);
private:
	boost::asio::serial_port* port;
};

#endif /* SERIALWRITER_H_ */
