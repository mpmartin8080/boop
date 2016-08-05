#include "ProxyTable.hpp"
#include <sstream>
#include <iostream>



void ProxyTable::addEntry (IPAddress client, IPAddress server)
{
	m_table.emplace(client,server);
	m_table.emplace(server,client);	
}

bool ProxyTable::removeEntry (IPAddress* key)
{
	if (m_table.erase(m_table[*key]) != 1)
		Log::Instance()->LogError("Unable to erase reverse table entry");
	if (m_table.erase(*key) != 1)
		Log::Instance()->LogError("Unable to erase table entry");
}

void ProxyTable::dumpTable()
{
	std::cout << "Table size: " << m_table.size() << std::endl;
	std::cout << "First IP:First Port | Second IP:Second Port" << std::endl;

	for (const auto &pair : m_table)
	{
		std::cout << pair.first.str() << ":" << pair.first.port() << " | ";
		std::cout << pair.second.str() << ":"  << pair.second.port() << std::endl;
	}
}

IPAddress ProxyTable::find(IPAddress srcip)
{
	std::unordered_map<IPAddress, IPAddress>::const_iterator dstip = m_table.find(srcip);

	if (dstip == m_table.end())
		return IPAddress ("0.0.0.0");
	else
		return dstip->second;
}
