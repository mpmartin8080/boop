#include "Global.hpp"
#include "IPAddress.hpp"
#include "ProxyTable.hpp"

#include <string>


using namespace std;

main (int argv, char** argc)
{

Log::Instance()->LogDebug("This is a test of the logging object");

cout << "Tried to log to syslog" << endl;

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


exit;

}

