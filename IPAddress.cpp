#include "IPAddress.hpp"
#include <arpa/inet.h>
#include <cstring>


IPAddress::IPAddress()
{
	m_socketaddress = new sockaddr_storage;
	Zero();
};

IPAddress::IPAddress(string address)
{
	m_socketaddress = new sockaddr_storage;
	Zero();
#ifdef USEIPV6
	inet_pton(AF_INET6, address.c_str(), &((struct sockaddr_in6 *)m_socketaddress->sin6_addr);
#else
	inet_pton(AF_INET, address.c_str(), &(((struct sockaddr_in *)m_socketaddress)->sin_addr));	
#endif // USEIPV6
}

IPAddress::IPAddress (sockaddr_storage existingip)
{
	m_socketaddress = new sockaddr_storage;
	*m_socketaddress = existingip;
}

string IPAddress::str()
{

#ifdef USEIPV6
	char tempOut[INET6_ADDRSTRLEN] ;
	inet_ntop(AF_INET6, (struct sockaddr_in6 *)m_socketaddress->sin6_addr, tempOut, sizeof(tempOut));
	return (string(tempOut));
#else
	return(string(inet_ntoa(((struct sockaddr_in *)m_socketaddress)->sin_addr)));
#endif
}

void IPAddress::setIP(sockaddr_storage newip)
{

	if (!m_socketaddress)
		m_socketaddress = new sockaddr_storage;
	*m_socketaddress = newip;
}

bool IPAddress::setIP(string address)
{
#ifdef USEIPV6
        if (inet_pton(AF_INET6, address.c_str(), &((struct sockaddr_in6 *)m_socketaddress->sin6_addr)) == 1)
#else
        if (inet_pton(AF_INET, address.c_str(), &(((struct sockaddr_in *)m_socketaddress)->sin_addr)) == 1)
#endif // USEIPV6
		return true;
	else
		return false;
}

void IPAddress::Zero()
{
	memset(m_socketaddress, 0, sizeof(sockaddr_storage));
}

