#if !defined PACKETHANDLER_HPP
#define PACKETHANDLER_HPP

#include "Global.hpp"
#include "IPAddress.hpp"
#include "UDPSocket.hpp"

// Base class for both inbound and outbound packet handling

class PacketHandler
{
public:
	// ctor/dtor
	PacketHandler(int inport);
	~PacketHandler();

	// methods
	PassDGram (ByteType* begin, ByteType* end);
	
private:
	// members
	UDPSocket m_insocket, m_outsocket;
	
};

#endif // PACKETHANDLER_HPP
