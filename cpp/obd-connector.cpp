#include <iostream>
#include <string>
#include <StandardPIDRequest.h>
#include <StandardPIDResponse.h>
#include <CommandSender.h>
#include <StandardPIDSender.h>
#include <SerialWriter.h>
#include <boost/asio.hpp>
#include "SerialReader.h"
#include "SerialMonitor.h"
#include "SerialEventBus.h"

int main() {
	boost::asio::io_service io;
	boost::asio::serial_port *serialPort = new boost::asio::serial_port(io, "/dev/pts/0");

	boost::asio::serial_port_base::parity parity;
	boost::asio::serial_port_base::flow_control flowControl;
	boost::asio::serial_port_base::stop_bits stopBits;

	serialPort->set_option(boost::asio::serial_port_base::baud_rate(115200));
	serialPort->set_option(boost::asio::serial_port_base::character_size(8));
	serialPort->set_option(boost::asio::serial_port_base::parity(parity.none));
	serialPort->set_option(boost::asio::serial_port_base::stop_bits(stopBits.one));
	serialPort->set_option(boost::asio::serial_port_base::flow_control(flowControl.none));

	SerialWriter *serialWriter = new SerialWriter(serialPort);

	CommandSender<StandardPIDRequest*> *commandSender
			= new StandardPIDSender(serialWriter);

	StandardPIDRequest* standardPIDRequest = new StandardPIDRequest();
	standardPIDRequest->setMode("01");
	standardPIDRequest->setPid("0C");

	commandSender->sendCommand(standardPIDRequest);

	SerialReader *serialReader = new SerialReader(serialPort);
	SerialEventBus *serialEventBus = new SerialEventBus();


	SerialMonitor *serialMonitor = new SerialMonitor(serialReader, serialEventBus);
	serialMonitor->monitor();
//	serialMonitor->stop();

	sleep(100);

	delete standardPIDRequest;
	delete serialWriter;
	delete serialPort;
	delete serialMonitor;
	delete commandSender;
}
