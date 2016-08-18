#include "Server.hpp"

#include <string>


Server::Server(int listenport) : m_running(false)
{
        char* logstr = new char[256];

	sprintf(logstr, "Starting server instance on port %d", listenport);
	Log::Instance()->LogDebug(std::string(logstr));

	p_demux = new Demultiplexer (listenport, &m_permsocket, &m_proxytable);

        this->m_thread = std::thread(&Server::ServerLoop, this);

	this->m_running = true;

	delete logstr;
}

Server::~Server()
{
	delete p_demux;
}

void Server::ServerLoop()
{
	std::unique_lock<std::mutex> lock(this->m_mutex);

	for ( ;; )
	{
		// Handle controller stuff
	}

	this->m_running = false;
	this->m_cv.notify_all();

}
