all: Maze.o 
	c++ -std=c++11 Maze.o -o maze
Maze.o: maze.cpp maze.h
	c++ -std=c++11 -c -g maze.cpp
clean:
	rm *.o maze
