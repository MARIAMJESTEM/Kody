CXX = g++
CXXFLAGS = -Wall -I.

OBJS = ulamki.o ul_main.o

pong: ulamki.o ul_main.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o ul.exe

.PHONY: clean

clean:
	rm -f *.o *~ core *~
