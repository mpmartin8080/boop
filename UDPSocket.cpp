#include "UDPSocket.hpp"


int UDPSocket::Bind (in_port_t port)
{
	ADDRSTRUCT serveraddr;
	memset (&serveraddr, 0, sizeof(serveraddr));
#ifdef USEIPV6
	serveraddr.sin6_addr = in6addr_any;
	serveraddr.sin6_family = AF_INET6;
	serveraddr.sin6_port = port;
#else
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = port;
#endif // USEIPV6

	return bind (this->m_sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
}

