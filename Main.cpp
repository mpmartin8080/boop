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

	Server server(4000);

	std::unique_lock<std::mutex> lock(*server.getMutex());

	while (server.isRunning())
	{
		server.getCV()->wait(lock);
	}

	Log::Instance()->LogDebug("Logging stopping");
	
	exit (0);

}

