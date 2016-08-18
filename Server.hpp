#ifndef SERVER_HPP
#define SERVER_HPP

#include "Global.hpp"
#include "Demultiplexer.hpp"
#include "Multiplexer.hpp"
#include "UDPSocket.hpp"
#include "ProxyTable.hpp"

#include <thread>
#include <mutex>
#include <condition_variable>


// Main server class that owns all other main resources

class Server
{
public:
        // ctor/dtor
        Server(int listenport);
        ~Server();


        // methods
	bool isRunning() { return m_running; }
	std::mutex* getMutex() { return &m_mutex; }
	std::condition_variable* getCV() { return &m_cv; }
private:
	void ServerLoop();

        // members
	UDPSocket m_permsocket;
	ProxyTable m_proxytable;
        Demultiplexer* p_demux;
        Multiplexer* ap_muxtable[MAXTABLESIZE];
	bool m_running;
	std::thread m_thread;
	std::mutex m_mutex;
	std::condition_variable m_cv;
#ifdef TESTBUILD
	TestController m_controller;
#else
	//Controller m_controller;
#endif // TESTBUILD
};


#endif // SERVER_HPP
