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
        // ctor/dtor
        Server(int listenport);
        ~Server() {};


        // methods



        // members
	UDPSocket permsocket;
	ProxyTable m_proxytable;
        Demultiplexer m_demux;
        Multiplexer* m_muxtable[MAXTABLESIZE];
#ifdef TESTBUILD
	TestController m_controller;
#else
	//Controller m_controller;
#endif // TESTBUILD


#endif // SERVER_HPP
