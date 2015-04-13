/*
 * StandardPIDResponse.h
 *
 *  Created on: Mar 28, 2015
 *      Author: ilies
 */

#ifndef STANDARDPIDRESPONSE_H_
#define STANDARDPIDRESPONSE_H_

#include <iostream>

class StandardPIDResponse {
public:
	StandardPIDResponse();
	~StandardPIDResponse();
	std::string getCommand();
	void setCommand(std::string command);
	std::string getResponse();
	void setResponse(std::string response);
private:
	std::string response;
	std::string command;
};

#endif /* STANDARDPIDRESPONSE_H_ */
