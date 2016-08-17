#include "UDPSocket.hpp"
#include <errno.h>


int UDPSocket::Bind (in_port_t port)
{
	char* logstr = new char[256];

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

	int retcode = bind (this->m_sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
	sprintf (logstr, "Bound UDPSocket %d with return code %d and errno %d", (int)this->m_sock, retcode, errno);
	Log::Instance()->LogDebug(std::string(logstr));
	return retcode;
	
}


int UDPSocket::receive (void * buf, IPAddress * srcaddr)
{
	char* logstr = new char[256];
	
	sockaddr_storage retaddr;
	socklen_t addrlen = sizeof (sockaddr_storage);
//	sprintf (logstr, "Got sockaddr_storage of size %d", (int)addrlen);
//	Log::Instance()->LogDebug(std::string(logstr));

	ssize_t recvlen = recvfrom(m_sock, buf, MTU, 0, (struct sockaddr *)&retaddr, &addrlen);

	if (recvlen < 1)
	{
//		sprintf(logstr, "Recevied from UDPSocket %d but got return of %d and errono %d", (int)m_sock, (int)recvlen, errno);
//		Log::Instance()->LogDebug(std::string(logstr));
		return (int)recvlen;
	}

	sprintf(logstr, "Recevied %d bytes on UDPSocket %d", (int)recvlen, (int)m_sock);
	Log::Instance()->LogDebug(std::string(logstr));

	srcaddr->setIP(retaddr);

	delete logstr;

	return (int)recvlen;

}

int UDPSocket::send (ByteType * buf, int size, IPAddress srvaddr)
{
	char* logstr = new char[256];
	
	int retcode = (int)sendto (m_sock, buf, (size_t)size, 0,  (struct sockaddr *)&srvaddr, sizeof(srvaddr));
	sprintf(logstr, "Sent %d bytes on UDPSocket %d", retcode, (int)m_sock);
	Log::Instance()->LogDebug(std::string(logstr));

	delete logstr;

	return retcode;
}

