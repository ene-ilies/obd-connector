/*
 * StringToHexDecoder.h
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#ifndef STRINGTOHEXDECODER_H_
#define STRINGTOHEXDECODER_H_

#include <iostream>
#include <map>

class StringToHexTransformer {
public:
	StringToHexTransformer();
	virtual ~StringToHexTransformer();
	unsigned char transform(std::string value);
	static std::map<char, char> charToHex;
};

#endif /* STRINGTOHEXDECODER_H_ */
