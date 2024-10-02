#include "Client.hpp"

#include <iostream>

namespace ServerLib
{
    void Client::PingServer()
	{
		ServerLib::net::message<CustomMsgTypes> msg;
		msg.header.id = CustomMsgTypes::ServerPing;

		// Caution with this...
		std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

		msg << timeNow;
		Send(msg);
	}

	void Client::MessageAll()
	{
		ServerLib::net::message<CustomMsgTypes> msg;
		msg.header.id = CustomMsgTypes::MessageAll;
		Send(msg);
	}
} // namespace ServerLib
