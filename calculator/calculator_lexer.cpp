// File: calculator_lexer.cpp
// Purpose: This file contains the implementation of the calculator lexer.
// Author: Robert Lowe
#include "calculator_lexer.h"

CalculatorLexer::CalculatorLexer() {
  // set up the token definitions in the lexer  
  _lex.add_token(ADD, make_regex("\\+"));
  _lex.add_token(SUB, make_regex("-"));
  _lex.add_token(MUL, make_regex("\\*"));
  _lex.add_token(DIV, make_regex("/"));
  _lex.add_token(POW, make_regex("^"));
  _lex.add_token(LPAREN, make_regex("\\("));
  _lex.add_token(RPAREN, make_regex("\\)"));
  _lex.add_token(INT, make_regex("[0-9]+"));
  _lex.add_token(REAL, make_regex("[0-9]+\\.[0-9]+"));
}

// set the input string to scan
void CalculatorLexer::input(const std::string &_input) {
  _lex.input(_input);
}

// return the input string being scanned
std::string CalculatorLexer::input() const {
  return _lex.input();
}

// Get the next token from the input string
Lexer::Token CalculatorLexer::next() {
  return _lex.next();
}