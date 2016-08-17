#ifndef DEMULTIPLEXER_HPP
#define DEMULTIPLEXER_HPP

#include "Global.hpp"
#include "ProxyTable.hpp"
#include "UDPSocket.hpp"

#include <thread>

class Demultiplexer 
{
public:
	// ctor/dtor
	Demultiplexer (int listenport, UDPSocket* permsocket, ProxyTable * table);
	~Demultiplexer ();

	// methods
	int passDGram (ByteType* buf, int size, IPAddress dstaddr);
	void * receiveHandler();

private:
	// member
	UDPSocket* m_listensocket;
	ProxyTable * m_proxytable;
        std::thread m_thread;

};


#endif // DEMULTIPLEXER_HPP

