#ifndef SERVER_HPP
#define SERVER_HPP

#include "Global.hpp"
#include "Demultiplexer.hpp"
#include "Multiplexer.hpp"
#include "UDPSocket.hpp"
#include "ProxyTable.hpp"


// Main server class that owns all other main resources

class Server
{
public:
        // ctor/dtor
        Server(int listenport);
        ~Server();


        // methods
	

private:
        // members
	UDPSocket m_permsocket;
	ProxyTable m_proxytable;
        Demultiplexer* p_demux;
        Multiplexer* ap_muxtable[MAXTABLESIZE];
#ifdef TESTBUILD
	TestController m_controller;
#else
	//Controller m_controller;
#endif // TESTBUILD
};


#endif // SERVER_HPP
