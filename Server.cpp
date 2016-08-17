#include "Server.hpp"

#include <string>


Server::Server(int listenport)
{
        char* logstr = new char[256];

	sprintf(logstr, "Starting server instance on port %d", listenport);
	Log::Instance()->LogDebug(std::string(logstr));

	p_demux = new Demultiplexer (listenport, &m_permsocket, &m_proxytable);

	delete logstr;
}

Server::~Server()
{
	delete p_demux;
}
