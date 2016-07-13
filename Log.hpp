#if !defined LOGGING_HPP
#define LOGGING_HPP

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/SyslogAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
#include "log4cpp/BasicLayout.hh"
#include "log4cpp/Priority.hh"
#include <string>

#define ERROR log4cpp::Priority::ERROR
#define INFO log4cpp::Priority::INFO
#define DEBUG log4cpp::Priority::DEBUG
#define WARNING log4cpp::Priority::WARNING


using namespace std;

class Log {
public:
	// ctor/dtor
	Log();
	~Log() {};

	// methods
	void LogMsg (int level, string msg) { m_root.log(level, msg); }
	void LogError (string msg) { m_root.error(msg); }
	void LogInfo (string msg) { m_root.info(msg); }
	void LogWarn (string msg) { m_root.warn(msg); }
	void LogDebug (string msg) { m_root.debug(msg.c_str()); }
	static Log* Instance();

private:
	// members
	log4cpp::Category& m_root;
	log4cpp::Appender* m_syslogApp;
	static Log* m_instance;
};



#endif // LOGGING_HPP

