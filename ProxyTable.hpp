#if !defined PROXYTABLE_HPP
#define PROXYTABLE_HPP

#include "Global.hpp"
#include "IPAddress.hpp"
#include <string>


class ProxyEntry {
public:
	// ctor/dtor
	ProxyEntry () { m_client.Zero(); m_server.Zero(); m_valid = false; }
	ProxyEntry (IPAddress* newclient, IPAddress* newserver)  : m_client(*(newclient->getIP())), m_server(*(newserver->getIP())), m_valid(true) {}
	~ProxyEntry () {}

	// methods
	IPAddress getClient () { return m_client; }
	void setClient(IPAddress newclient) { m_client = newclient; }
	IPAddress getServer () { return m_server; }
	void setServer(IPAddress newserver) { m_server = newserver; }
	bool isValid() { return m_valid; }
	void setValid(bool isvalid) { m_valid = isvalid; }

private:
	// members
	IPAddress m_client;
	IPAddress m_server;
	bool m_valid;
};


class ProxyTable {
public:
	// ctor/dtor
	ProxyTable ();
	~ProxyTable ();

	// methods
	int addEntry (IPAddress* client, IPAddress* server);
	bool removeEntry (int index);
	std::string listEntry(int index);
	int space();

private:
	// members
	ProxyEntry* m_table[MAXTABLESIZE];

};



#endif // PROXYTABLE_HPP
