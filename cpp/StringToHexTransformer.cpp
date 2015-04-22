/*
 * StringToHexDecoder.cpp
 *
 *  Created on: Apr 18, 2015
 *      Author: ilies
 */

#include "StringToHexTransformer.h"
#include <bitset>

std::map<char, char> StringToHexTransformer::charToHex;

void initMap() {
	StringToHexTransformer::charToHex['0'] = 0x0;
	StringToHexTransformer::charToHex['1'] = 0x1;
	StringToHexTransformer::charToHex['2'] = 0x2;
	StringToHexTransformer::charToHex['3'] = 0x3;
	StringToHexTransformer::charToHex['4'] = 0x4;
	StringToHexTransformer::charToHex['5'] = 0x5;
	StringToHexTransformer::charToHex['6'] = 0x6;
	StringToHexTransformer::charToHex['7'] = 0x7;
	StringToHexTransformer::charToHex['8'] = 0x8;
	StringToHexTransformer::charToHex['9'] = 0x9;
	StringToHexTransformer::charToHex['A'] = 0xA;
	StringToHexTransformer::charToHex['B'] = 0xB;
	StringToHexTransformer::charToHex['C'] = 0xC;
	StringToHexTransformer::charToHex['D'] = 0xD;
	StringToHexTransformer::charToHex['E'] = 0xE;
	StringToHexTransformer::charToHex['F'] = 0xF;
}

StringToHexTransformer::StringToHexTransformer() {
	initMap();
}

StringToHexTransformer::~StringToHexTransformer() {
}

unsigned char StringToHexTransformer::transform(std::string value) {
	unsigned char result = 0;

	for (int i = 0; i < value.size(); i++) {
		result = result << 4;
		result = result | StringToHexTransformer::charToHex[value[i]];
	}

	return result;
}

