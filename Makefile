all: mid19 unittest

mid19:
	g++ -Wall mid19.cpp data.h -o mid19

unittest:
	g++ -Wall -DUNIT_TEST mid19.cpp data.h -o test
