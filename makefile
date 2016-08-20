CC=g++
CFLAGS=-I. -std=c++11 -Wfatal-errors -D TESTBUILD
DEPS = 	Global.hpp 

OBJ = 	Global.o \
	Log.o \
	Main.o \
	IPAddress.o \
	ProxyTable.o \
	UDPSocket.o \
	Demultiplexer.o \
	Server.o \
	Controller.o \
	TestControlServer.o

LIBS=-lm -llog4cpp -lpthread -lonion_static -lpam -lgnutls -lgcrypt

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

boop: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core boop

