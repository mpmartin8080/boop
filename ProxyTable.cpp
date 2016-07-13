#include "ProxyTable.hpp"
#include <sstream>


ProxyTable::ProxyTable ()
{
	for (int i = 0; i < MAXTABLESIZE; i++)
		m_table[i] = new ProxyEntry();
}

ProxyTable::~ProxyTable ()
{
	for (int i = 0; i < MAXTABLESIZE; i++)
		delete (m_table[i]);
}

int ProxyTable::addEntry (IPAddress client, IPAddress server)
{
	for (int i = 0; i < MAXTABLESIZE; i++)
	{
		if (!m_table[i]->isValid())
		{
			m_table[i]->setClient(client);
			m_table[i]->setServer(server);
			m_table[i]->setValid(true);
			return i;
		}
	}
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
		return "";
	std::stringstream tempstr;
	tempstr << m_table[index]->getClient().str() << ":" << m_table[index]->getClient().port() << " | ";
	tempstr << m_table[index]->getServer().str() << ":" << m_table[index]->getServer().port();
	return tempstr.str();
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

