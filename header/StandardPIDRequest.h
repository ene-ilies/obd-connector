/*
 * StandardPIDRequest.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#ifndef STANDARDPIDREQUEST_H_
#define STANDARDPIDREQUEST_H_

#include <iostream>

class StandardPIDRequest {
private:
	std::string mode;
	std::string pid;
public:
	StandardPIDRequest();
	std::string getPid();
	void setPid(std::string pid);
	std::string getMode();
	void setMode(std::string mode);
};

#endif /* STANDARDPIDREQUEST_H_ */
