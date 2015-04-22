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
#include "CommandsTriggerer.h"
#include "StringToHexTransformer.h"

int main(int argc, char** args) {
	boost::asio::io_service io;
	const char* device = args[1];

	std::cout << "Connecting to: " << device << std::endl;

	boost::asio::serial_port *serialPort = new boost::asio::serial_port(io, device);

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

	SerialReader *serialReader = new SerialReader(serialPort);
	SerialEventBus *serialEventBus = new SerialEventBus();

	SerialMonitor *serialMonitor = new SerialMonitor(serialReader, serialEventBus);
	serialMonitor->monitor();

	CommandsTriggerer *commandsTriggerer = new CommandsTriggerer(commandSender);
	commandsTriggerer->trigger();

	sleep(5);

	serialMonitor->stop();
	commandsTriggerer->stop();

	serialMonitor->join();
	commandsTriggerer->join();

	delete commandsTriggerer;
	delete serialWriter;
	delete serialPort;
	delete serialMonitor;
	delete commandSender;
}
