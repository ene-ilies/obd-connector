/*
 * SerialReader.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: ilies
 */

#include "SerialReader.h"

SerialReader::SerialReader(boost::asio::serial_port *port) {
	this->port = port;
}

SerialReader::~SerialReader() {
}

std::string SerialReader::readLine() {
	std::string line;

	char response;
	do {
		boost::asio::read(*port, boost::asio::buffer(&response, 1));

		line += response;
	} while (response != '\r' );

	return line;
}

