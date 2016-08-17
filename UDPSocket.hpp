#if !defined UDPSOCKET_HPP
#define UDPSOCKET_HPP

// Wrapper for standard BSD UDP socket

#include "Global.hpp"
#include "IPAddress.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#ifdef USEIPV6
	#define FAMILY AF_INET6
#else
	#define FAMILY AF_INET
#endif // USEIPV6

class UDPSocket 
{
public:
	// simplified ctor
	UDPSocket () : m_sock (socket(FAMILY, SOCK_DGRAM, 0)) {};
	// dtor
	~UDPSocket () { Log::Instance()->LogDebug("UDPSocket dtor"); close(m_sock); }

	// methods
	int Bind (in_port_t port);
	int receive (void * buf, IPAddress * srcaddr);
	int send (ByteType * buf, int size, IPAddress srvaddr);
	int Close() { return close(m_sock); }

private:
	// members
	int m_sock;
};

#endif // UDPSOCKET_HPP

