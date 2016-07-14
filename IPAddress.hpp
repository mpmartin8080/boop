#ifndef IP_ADDRESS_HPP
#define IP_ADDRESS_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>

using namespace std;

class IPAddress {

public:
	// ctor/dtor
	IPAddress ();
	IPAddress (string address);
	IPAddress (sockaddr_storage existingip);
	~IPAddress() {} 

	// methods
	string str();
	sockaddr_storage* getIP() { return m_socketaddress; }
	void setIP(sockaddr_storage newip);
	bool setIP(string address);
	void Zero();
#ifdef USEIPV6
	void setPort (int port) { ((struct sockaddr_in6 *)m_socketaddress)->sin6_port = (in_port_t)port; }
	in_port_t port() { return (((struct sockaddr_in6 *)m_socketaddress)->sin6_port); }
#else
	void setPort (int port) { ((struct sockaddr_in *)m_socketaddress)->sin_port = (in_port_t)port; }
	in_port_t port() { return (((struct sockaddr_in *)m_socketaddress)->sin_port); };
#endif // USEIPV6

private:
	// members
	sockaddr_storage* m_socketaddress;
};


#endif // IP_ADDRESS_HPP

