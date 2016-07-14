#include "ProxyTable.hpp"
#include <sstream>
#include <iostream>


ProxyTable::ProxyTable ()
{
	for (int i = 0; i < MAXTABLESIZE; i++)
		m_table[i] = new ProxyEntry();
}

ProxyTable::~ProxyTable ()
{
//	for (int i = 0; i < MAXTABLESIZE; i++)
//		delete (m_table[i]);
}

int ProxyTable::addEntry (IPAddress* client, IPAddress* server)
{
	for (int i = 0; i < MAXTABLESIZE; i++)
	{
		if (!m_table[i]->isValid())
		{
			std::cout << "Found empty table slot at index " << i << std::endl;
			m_table[i]->setClient(*client);
			std::cout << "Set client IP" << std::endl;
			m_table[i]->setServer(*server);
			std::cout << "Set server IP" << std::endl;
			m_table[i]->setValid(true);
			std::cout << "Set entry to valid" << std::endl;
			return i;
		}
	}
	std::cout << "Proxy table is full" << std::endl;
	return -1;
}

bool ProxyTable::removeEntry (int index)
{
	if (m_table[index]->isValid())
	{
		m_table[index]->getClient().Zero();
		m_table[index]->getServer().Zero();
		m_table[index]->setValid(false);
		return true;
	}
	else
		return false;
}

std::string ProxyTable::listEntry(int index)
{
	if (!m_table[index]->isValid())
		return "Invalid";
	else
	{
		IPAddress clientip = m_table[index]->getClient();
		IPAddress serverip = m_table[index]->getServer();
		std::stringstream tempstr;
		tempstr << clientip.str() << ":" << clientip.port() << " | ";
		tempstr << serverip.str() << ":"  << serverip.port();
		return tempstr.str();
	}
}

int ProxyTable::space()
{
	int used = 0;
	for (int i = 0; i < MAXTABLESIZE; i++)
	{
		if (m_table[i]->isValid())
			used++;
	}
	return MAXTABLESIZE - used;
}

