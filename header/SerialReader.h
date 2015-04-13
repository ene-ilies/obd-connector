/*
 * SerialReader.h
 *
 *  Created on: Apr 10, 2015
 *      Author: ilies
 */

#ifndef SERIALREADER_H_
#define SERIALREADER_H_

#include <boost/asio.hpp>
#include <iostream>

class SerialReader {
public:
	SerialReader(boost::asio::serial_port *port);
	virtual ~SerialReader();
	std::string readLine();
private:
	boost::asio::serial_port *port;
};

#endif /* SERIALREADER_H_ */
