#if !defined PACKETHANDLER_HPP
#define PACKETHANDLER_HPP

#include "Global.hpp"
#include "IPAddress.hpp"
#include "UDPSocket.hpp"

#include <thread>

// Base class for both inbound and outbound packet handling

class PacketHandler
{
public:
	// ctor/dtor
	PacketHandler(int inport, IPAddress srcaddr, IPAddress dstaddr);
	~PacketHandler();

private:
	// methods
	int passDGram (ByteType* buf, size_t size);
	void* receiveHandler ();

	// members
	UDPSocket m_insocket, m_outsocket;
	IPAddress m_srcaddr, m_dstaddr;
	std::thread m_thread;
	ByteType m_packetbuf[MTU];
	
};

#endif // PACKETHANDLER_HPP
