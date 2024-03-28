// File: lexer_test.cpp
// Purpose: A small interactive test of the calculator lexer.
// Author: Robert Lowe

#include <iostream>
#include "calculator_lexer.h"

int main() {
  std::string input;
  CalculatorLexer lex;
  
  for(;;) {
    // get the next line of input (if there is one)
    std::cout << "> ";
    getline(std::cin, input);
    if(!std::cin) break;

    // set up the lexer to scan the input
    lex.input(input);

    // Print all the tokens in the input
    Lexer::Token tok;
    while((tok = lex.next()).tok != CalculatorLexer::EOI) {
      // print out the token fields
      std::cout << "tok: " << tok.tok << " "
                << "pos: " << tok.pos << " " 
                << "lexeme: " << tok.lexeme << std::endl;
    }
  }
}