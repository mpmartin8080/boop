#include "Server.hpp"

#include <string>


Server::Server(int listenport) : m_running(false) 
{

	p_demux =  std::make_shared<Demultiplexer>(listenport, &m_permsocket, &m_proxytable);
	m_controller = std::make_shared<Controller>(this);
        this->m_thread = std::thread(&Server::ServerLoop, this);
	this->m_running = true;
}

Server::~Server()
{
	// Nothing yet
}

void Server::ServerLoop()
{
	std::unique_lock<std::mutex> lock(this->m_mutex);

	for ( ;; )
	{
		// TODO: Handle controller stuff
	}

	this->m_running = false;
	this->m_cv.notify_all();

}
