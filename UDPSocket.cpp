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


int UDPSocket::receive (void * buf, IPAddress expected)
{
	ADDRSTRUCT retaddr;
	socklen_t addrlen = ADDRSIZE;

	ssize_t recvlen = recvfrom(m_sock, buf, MTU, 0, (struct sockaddr *)&retaddr, &addrlen);

	IPAddress tempaddr(*((sockaddr_storage *)&retaddr));

	if ((tempaddr.port() != expected.port()) or (tempaddr.getIP() != expected.getIP()))
		return -1;
	else
		return (int)recvlen;
}

int UDPSocket::send (void * buf, int size, IPAddress srvaddr)
{
	return (int)sendto (m_sock, buf, (size_t)size, 0,  (struct sockaddr *)&srvaddr, sizeof(srvaddr));
}

