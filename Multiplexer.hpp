#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP

#include "Global.hpp"
#include "ProxyTable.hpp"
#include "UDPSocket.hpp"

#include <thread>

class Multiplexer 
{
	// ctor/dtor
	Multiplexer (IPAddress externaladdr, IPAddress internaladdr, UDPSocket * externalsocket);
	~Multiplexer ();

	// methods
	bool isActive() { return m_active; }
	int passDGram (ByteType* buf, int size, IPAddress dstaddr);
	void * receiveHandler();


	// member
	bool m_active;
	UDPSocket * p_externalsocket;
	UDPSocket m_internalsocket;
	IPAddress m_internaladdr, m_externaladdr;
        std::thread m_thread;

};


#endif // MULTIPLEXER_HPP

