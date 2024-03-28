TARGETS=calculator lexer_test

#compiler information
LD=g++
CC=g++
CXX=g++
CXXFLAGS=-g -Ilib
LDFLAGS=-Llib
LDLIBS=-lreglex

all: $(TARGETS)
calculator: calculator.o
lexer_test: lexer_test.o calculator_lexer.o

clean:
	rm -f $(TARGETS) *.o