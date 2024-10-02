#pragma once
#include <serverlib_headers.hpp>

namespace ServerLib
{
    enum class CustomMsgTypes : uint32_t
    {
        ServerAccept,
        ServerDeny,
        ServerPing,
        MessageAll,
        ServerMessage,
    };

    class Server: public net::server_interface<CustomMsgTypes>
    {
    public:
        Server(uint16_t nPort);
    private:
        virtual bool OnClientConnect(std::shared_ptr<net::connection<CustomMsgTypes>> client);
        virtual void OnClientDisconnect(std::shared_ptr<net::connection<CustomMsgTypes>> client);
        virtual void OnMessage(std::shared_ptr<net::connection<CustomMsgTypes>> client, net::message<CustomMsgTypes>& msg);
        

    };
    
} // namespace ServerLib
