#include "Demultiplexer.hpp"

Multiplexer::Multiplexer (IPAddress extaddr, IPAddress intaddr, UDPSocket * externalsocket) : m_active(false)
{
	if (externalsocket)
		p_externalsocket = externalsocket;
	else
		Log::Instance()->LogError("Got null external socket pointer");

	
        m_listensocket->Bind(listenport);

        m_thread = std::thread(&Multiplexer::receiveHandler, this);
	m_active = true;
}

Demultiplexer::~Demultiplexer()
{
        this->m_listensocket->Close();
        this->m_thread.join();
}

int Demultiplexer::passDGram (ByteType* buf, int size, IPAddress dstaddr)
{
        return this->m_listensocket->send(buf, size, dstaddr);
}

void* Demultiplexer::receiveHandler()
{
	ByteType buffer[MTU];
	IPAddress srcaddr;
	IPAddress emptyip = IPAddress("0.0.0.0");
	

        for ( ;; )
        {
		memset (buffer, 0, sizeof(buffer));
		srcaddr.setIP("0.0.0.0");

                int recvd = this->m_listensocket->receive (&buffer[0], &srcaddr);
                if (recvd < 1)
                {
                        Log::Instance()->LogError("Bad read on inbound socket");
                        continue; // TODO proper error handling on bad data receipt
                }
		if (recvd > MTU)
		{
			Log::Instance()->LogError("Read more bytes than MTU size. THIS SHOULD NEVER BE ABLE TO HAPPEN.");
			continue;
		}

		// Lookup destination in table
		IPAddress dstip = m_proxytable->find(srcaddr.str());
		if (dstip == emptyip) // Can't find source IP in proxy table
		{
			Log::Instance()->LogDebug("Received packet with unknown source IP");
			continue;
		}


                int sent = this->passDGram (&buffer[0], recvd, dstip);
                if (sent < 1)
                        Log::Instance()->LogError("Bad write on outbound socket");

        }
}

