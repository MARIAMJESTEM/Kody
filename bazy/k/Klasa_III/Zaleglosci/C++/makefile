CXX = g++
CXXFLAGS = -Wall -I.

OBJS = tree.o tree_main.o

pong: tree.o tree_main.o
	$(CXX) $(CXXFLAGS) $(OBJS) -o tree.exe

.PHONY: clean

clean:
	rm -f *.o *~ core *~
