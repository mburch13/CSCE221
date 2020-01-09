all: My_stack.o Application.o
	c++ -std=c++11 My_stack.o Application.o -o main
My_stack.o: My_stack.cpp My_stack.h
	c++ -std=c++11 -c -g My_stack.cpp
Application.o: Application.cpp My_stack.h
	c++ -std=c++11 -c -g Application.cpp
clean:
	rm *.o main
