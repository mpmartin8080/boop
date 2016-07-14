#if !defined GLOBAL_HPP
#define GLOBAL_HPP

#if !defined MAXTABLESIZE
	#define MAXTABLESIZE 1024
#endif

#include <stdlib.h>
#include <string.h>


#ifdef USEIPV6
        #define FAMILY AF_INET6
	#define ADDRSIZE sizeof(struct sockaddr_in6)
	#define ADDRSTRUCT sockaddr_in6
#else
        #define FAMILY AF_INET
	#define ADDRSIZE sizeof(struct sockaddr_in)
	#define ADDRSTRUCT sockaddr_in
#endif // USEIPV6

#define MTU 1400

#include "Log.hpp"

typedef unsigned char ByteType;

#endif // GLOBAL_HPP
