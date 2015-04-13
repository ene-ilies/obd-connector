/*
 * StandardPIDRequest.cpp
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#include "StandardPIDRequest.h"

StandardPIDRequest::StandardPIDRequest() {
}

std::string StandardPIDRequest::getMode() {
	return mode;
}

void StandardPIDRequest::setMode(std::string mode) {
	this->mode = mode;
}

std::string StandardPIDRequest::getPid() {
	return pid;}void StandardPIDRequest::setPid(std::string pid) {	this->pid = pid;}
