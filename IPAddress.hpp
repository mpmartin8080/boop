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
	string str() const;
	sockaddr_storage* getIP() const { return m_socketaddress; }
	void setIP(sockaddr_storage newip);
	bool setIP(string address);
	void Zero();
#ifdef USEIPV6
	void setPort (int port) { ((struct sockaddr_in6 *)m_socketaddress)->sin6_port = (in_port_t)port; }
	in_port_t port() const { return (((struct sockaddr_in6 *)m_socketaddress)->sin6_port); }
#else
	void setPort (int port) { ((struct sockaddr_in *)m_socketaddress)->sin_port = (in_port_t)port; }
	in_port_t port() const { return (((struct sockaddr_in *)m_socketaddress)->sin_port); };
#endif // USEIPV6

	IPAddress& operator= (const IPAddress other);

	// operators
	bool operator== (IPAddress& that) { return ((this->str().compare(that.str()) == 0) && (this->port() == that.port())); }
	IPAddress& operator= (const IPAddress& other);

private:
	// members
	sockaddr_storage* m_socketaddress;
};


namespace std {
// specialization of std::hash for IP object (used in ProxyTable)
template<> struct hash<IPAddress>
{
    size_t operator()(IPAddress const& ip) const 
    {
        size_t hash1 = hash<std::string>()(ip.str());
        size_t hash2 = hash<in_port_t>()(ip.port());
        return hash1 ^ (hash2 << 1); 
    }
};

// specialization of std::equal_to for IP object
template<> struct equal_to<IPAddress>
{
	bool operator()(const IPAddress &left, const IPAddress &right) const
	{
	    return ((left.str().compare(right.str()) == 0) && (left.port() == right.port()));
	}
};

} // namespace std

#endif // IP_ADDRESS_HPP

