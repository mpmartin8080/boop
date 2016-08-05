#include "Server.hpp"


Server::Server(int listenport) : m_demux(listenport, &m_permsocket, &m_proxytable)
{
	Log::Instance()->LogDebug("Starting server instance");
}


