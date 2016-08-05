#if !defined PROXYTABLE_HPP
#define PROXYTABLE_HPP

#include "Global.hpp"
#include "IPAddress.hpp"

#include <string>
#include <unordered_map>


class ProxyTable {
public:
	// methods
	void addEntry (IPAddress client, IPAddress server);
	bool removeEntry (IPAddress* key);
	void dumpTable ();
	int size () { return (int) m_table.size(); }
	IPAddress find(IPAddress srcip);

private:
	// members
	unordered_map<IPAddress, IPAddress> m_table;

};



#endif // PROXYTABLE_HPP
