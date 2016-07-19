CC=g++
CFLAGS=-I. -std=c++11
DEPS = 	Global.hpp 

OBJ = 	Global.o \
	Log.o \
	Testmain.o \
	IPAddress.o \
	ProxyTable.o \
	UDPSocket.o \
	PacketHandler.o

LIBS=-lm -llog4cpp -lpthread -lonion_static -lpam -lgnutls -lgcrypt

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

boop: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *.o *~ core boop

