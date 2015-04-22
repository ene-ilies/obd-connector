/*
 * ResponseDecoder.h
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#ifndef RESPONSEDECODER_H_
#define RESPONSEDECODER_H_

#include <iostream>

class ResponseDecoder {
public:
	virtual ~ResponseDecoder() {}
	virtual std::string decode(std::string response) = 0;
};

#endif /* RESPONSEDECODER_H_ */
