/*
 * SerialWriter.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: ilies
 */

#include "SerialWriter.h"

const char SerialWriter::EOL = '\n';

SerialWriter::SerialWriter(boost::asio::serial_port *port) {
	this->port = port;
}

SerialWriter::~SerialWriter() {
}

void SerialWriter::writeLine(std::string line) {
	boost::system::error_code error;
	boost::asio::write(*this->port, boost::asio::buffer(line.c_str(), line.size()), error);
	boost::asio::write(*this->port, boost::asio::buffer(&SerialWriter::EOL, 1), error);
}

