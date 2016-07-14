#include "PacketHandler.hpp"



PacketHandler::PacketHandler(int inport)
{
	m_insocket.Bind(inport);
	m_outsocket.Bind(0);
}

PacketHandler::~PacketHandler()
{
}

PacketHandler::PassDGram (ByteType* begin, ByteType* end)
{
	


}
