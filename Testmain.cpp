#include "Global.hpp"
#include "IPAddress.hpp"
#include "ProxyTable.hpp"
#include "Server.hpp"

#include <string>
#include <condition_variable>
#include <mutex>

using namespace std;

main (int argv, char** argc)
{

	Log::Instance()->LogDebug("Logging started");

	/*
	IPAddress* ip = new IPAddress("127.0.0.1");

	cout << "IP test: set 127.0.0.1, got " << ip->str() << endl;

	ip->setPort(3000);

	cout << "IP test: set port 3000, got " << ip->port() << endl;

	IPAddress* ip2 = new IPAddress(*(ip->getIP()));

	ip2->setIP("127.0.0.2");

	cout << "IP2 test: set 127.0.0.2, got " << ip2->str() << endl;

	ip2->setPort(3001);

	cout << "IP2 test: set port 3001, got " << ip2->port() << endl;

	ProxyTable* testTable = new ProxyTable;

	cout << "Created new empty proxy table" << endl;

	cout << "Empty table size is " << testTable->size() << endl;

	testTable->addEntry(*ip, *ip2);

	testTable->dumpTable();
	*/

	
	std::cout << "Starting server" << std::endl;

	Server server(4000);

	std::unique_lock<std::mutex> lock(*server.getMutex());
	while (server.isRunning())
	{
		server.getCV()->wait(lock);
		std::cout << "Ended wait for server thread" << std::endl;
	}
	
	exit (0);

}

