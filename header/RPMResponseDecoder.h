/*
 * RPMResponseDecoder.h
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#ifndef RPMRESPONSEDECODER_H_
#define RPMRESPONSEDECODER_H_

#include "ResponseDecoder.h"
#include "StringToHexTransformer.h"
#include <iostream>
#include <vector>

class RPMResponseDecoder : ResponseDecoder {
public:
	RPMResponseDecoder(StringToHexTransformer* transformer);
	virtual ~RPMResponseDecoder();
	std::string decode(std::string response);
private:
	std::vector<unsigned char> data;
	StringToHexTransformer* transformer;
};

#endif /* RPMRESPONSEDECODER_H_ */
