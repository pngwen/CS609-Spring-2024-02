TARGETS=regex_test
REGEX_LIB=regex_node.o character_node.o group_node.o zero_node.o one_node.o or_node.o range_node.o optional_node.o inverse_node.o
LD=g++
CC=g++
CXX=g++
CXXFLAGS=-g 


regex_test: regex_test.o $(REGEX_LIB)

clean:
	rm -f *.o $(TARGETS)