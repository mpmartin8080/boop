#include "Global.hpp"
#include "IPAddress.hpp"
#include "ProxyTable.hpp"

#include <string>


using namespace std;

main (int argv, char** argc)
{

	IPAddress* clientip = new IPAddress("192.168.15.41");
	cout << "Socket test: set client IP" << clientip->str() << endl;

	clientip->setPort(3000);
	cout << "Socket test: set client port " << clientip->port() << endl;

	IPAddress* serverip = new IPAddress("192.168.15.42");

	cout << "Socket test: set server IP " << serverip->str() << endl;

	serverip->setPort(3001);
	cout << "Socket test: set server port " << serverip->port() << endl;

	PacketHandler clienthandler* = new PacketHandler(3000, clientip, serverip);
	PacketHandler serverhandler* = new PacketHandler(3001, serverip, clientip);
	



}

