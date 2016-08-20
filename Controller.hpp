#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#ifdef TESTBUILD
    #include "TestControlServer.hpp"
#else
    #include "ControlServer.hpp"
#endif
#include "IPAddress.hpp"
#include "Server.hpp"


class Server;

enum Command { ADD, DELETE, TIMEOUT };

struct ControlCmd
{
	unsigned char cmd;
	IPAddress ip1;
	IPAddress ip2;
};

class Controller
{
public:
	// ctor/dtor
	Controller(Server* that);
	~Controller() {}

	// methods


private:
	// members
	void* p_callback;
	Server * p_that;
#ifdef TESTBUILD
	std::shared_ptr<TestControlServer> m_controlsrv;
#else
	std::shared_ptr<ControlServer> m_controlsrv;
#endif
	

};





#endif // CONTROLLER_HPP
