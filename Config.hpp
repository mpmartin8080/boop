#ifndef CONFIG_HPP
#define CONFIG_HPP

// Singleton configuration class

class Config
{
public:
	Config();
	~Config() {}

	// Getters/Setters
	int getControlPort() { return (int)m_controlIP.getPort(); }


private:
	// Config storage
	IPAddress m_controlIP;
	IPAddress m_listenIP;
	


#endif // CONFIG_HPP
