#include "Log.hpp"
#include "IPAddress.hpp"

#include <stdlib.h>


using namespace std;

main (int argv, char** argc)
{

IPAddress* ip = new IPAddress("127.0.0.1");

cout << "IP test: set 127.0.0.1, got " << ip->str() << std::endl;

ip->setPort(3000);

cout << "IP test: set port 3000, got " << ip->port() << std::endl;
	
Log::Instance()->LogDebug("This is a test of the logging object");

cout << "Tried to log to syslog" << std::endl;

exit;

}
