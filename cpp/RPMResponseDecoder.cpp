/*
 * RPMResponseDecoder.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#include "RPMResponseDecoder.h"
#include <sstream>
#include <stdio.h>

RPMResponseDecoder::RPMResponseDecoder(StringToHexTransformer* transformer) {
	this->transformer = transformer;
}

RPMResponseDecoder::~RPMResponseDecoder() {
}

std::string RPMResponseDecoder::decode(std::string response) {
	std::istringstream iss(response);

//	std::cout << "command: " << response << std::endl;

	do {
		std::string byte;
		iss >> byte;

		if (!byte.empty()) {
			data.push_back(transformer->transform(byte));
		}
	} while (iss);

//	std::cout << "Size: " << (int) data.size() << std::endl;

	if (data.size() != 4) {
		std::cout << "Invalid data length for RPM" << std::endl;
	}

//	std::cout << "Ack: " << (int) data[0] << std::endl;

	if (data[0] != 65) {
		std::cout << "Invalid acknoledge byte" << std::endl;
	}

//	std::cout << "Cbyte: " << (int) data[1] << std::endl;

	if (data[1] != 12) {
		std::cout << "Invalid command byte" << std::endl;
	}

//	std::cout << "A: " << (int) data[2] << std::endl;
//	std::cout << "B: " << (int) data[3] << std::endl;

	int rpm = ((data[2] * 256) + data[3]) / 4;
	char rpms[20];
	sprintf(rpms, "%d RPM", rpm);
//	std::cout << rpms << std::endl;

	return rpms;
}

