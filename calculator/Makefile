TARGETS=calculator lexer_test
CALCULATOR_OBJ= add_node.o\
				        ast_node.o\
								ref_env.o\
								binop_node.o\
								calculator_lexer.o\
								calculator_parser.o\
								divide_node.o\
								multiply_node.o\
								number_node.o\
								pow_node.o\
								subtract_node.o\
								ref_node.o\
								assign_node.o\

#compiler information
LD=g++
CC=g++
CXX=g++
CXXFLAGS=-g -Ilib
LDFLAGS=-Llib
LDLIBS=-lreglex

all: $(TARGETS)
calculator: calculator.o $(CALCULATOR_OBJ)
lexer_test: lexer_test.o calculator_lexer.o

clean:
	rm -f $(TARGETS) *.o