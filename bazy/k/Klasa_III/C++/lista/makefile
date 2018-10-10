CXX = g++
CXXFLAGS = -Wall -I.

OBJS = lista.o lista_main.o

pong: lista.o lista_main.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o lista.exe

.PHONY: clean

clean:
	rm -f *.o *~ core *~
