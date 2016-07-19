#include "PacketHandler.hpp"



PacketHandler::PacketHandler(int inport, IPAddress srcaddr, IPAddress dstaddr) : m_srcaddr (srcaddr), m_dstaddr (dstaddr)
{
	this->m_insocket.Bind(inport);
	this->m_outsocket.Bind(0);

	this->m_thread = std::thread(&PacketHandler::receiveHandler, this);
}

PacketHandler::~PacketHandler()
{
	this->m_insocket.Close();
	this->m_outsocket.Close();
	this->m_thread.join();
}

int PacketHandler::passDGram (ByteType* buf, size_t size)
{
	return this->m_outsocket.send(buf, size, this->m_dstaddr);
}

void* PacketHandler::receiveHandler()
{

	for ( ;; )
	{
		int recvd = this->m_insocket.receive (this->m_packetbuf, this->m_srcaddr);
		if (recvd < 1)
		{
			Log::Instance()->LogError("Bad read on inbound socket");
			continue; // TODO proper error handling on bad data receipt
		}
		int sent = this->passDGram (this->m_packetbuf, recvd);
		if (sent < 1)
			Log::Instance()->LogError("Bad write on outbound socket");

	}
}

