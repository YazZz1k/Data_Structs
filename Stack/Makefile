stack: stack.o stack_test.o
	g++ stack.o stack_test.o -o stack
stack.o: stack.hpp stack.cpp
	g++ -c stack.cpp
stack_test.o: stack_test.cpp
	g++ -c stack_test.cpp
