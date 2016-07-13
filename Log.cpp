#include "Log.hpp"

Log* Log::m_instance;

Log::Log() : m_root(log4cpp::Category::getRoot())
{
	m_syslogApp = new log4cpp::SyslogAppender("syslog","boop", log4cpp::Priority::WARN);
//	m_syslogApp = new log4cpp::OstreamAppender("console", &std::cout);
	m_syslogApp->setLayout(new log4cpp::BasicLayout());

	m_root.setPriority(DEBUG); // set default priority
	m_root.addAppender(m_syslogApp);

	std::cout << "Initialized logging object" << std::endl;
}

Log* Log::Instance()
{
	if (!m_instance)
	{
		std::cout << "No existing instance of logging object, so creating new one" << std::endl;
		m_instance = new Log;
	}
	return m_instance;
}

