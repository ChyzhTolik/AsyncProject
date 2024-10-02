#include <iostream>
#include "Server/Server.hpp"

int main()
{
    std::cout<<"Hi, it's Server"<<std::endl;
    ServerLib::Server server(static_cast<uint16_t>(60000));

    server.Start();

	while (1)
	{
		server.Update(-1, true);
	}
}