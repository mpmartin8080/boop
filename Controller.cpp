#include "Controller.hpp"


Controller::Controller(Server * that) : p_that(that)
{
#ifdef TESTBUILD
	auto m_controlsrv = std::make_shared<TestControlServer>;
#else
	auto m_controlsrv = std::make_shared<ControlServer>;
#endif

}
