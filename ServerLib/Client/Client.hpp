#pragma once
#include <serverlib_headers.hpp>

enum class CustomMsgTypes : uint32_t
{
	ServerAccept,
	ServerDeny,
	ServerPing,
	MessageAll,
	ServerMessage,
};

namespace ServerLib
{
	class Client: public net::client_interface<CustomMsgTypes>
	{
	public:
		void PingServer();
		void MessageAll();
	};
	
} // namespace ServerLib
