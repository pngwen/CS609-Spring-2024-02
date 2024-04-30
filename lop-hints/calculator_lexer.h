// File: calculator_lexer.h
// Purpose: This file contains the definition of the calculator lexer.
// Author: Robert Lowe
#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H
#include "lib/reglex.h"
#include <string.h>
#include <iostream>

class CalculatorLexer {
public:
  CalculatorLexer(std::istream &_is);

  // Lexer Tokens
  enum token_type {
    EOI = Lexer::END_OF_INPUT,
    INVALID = Lexer::INVALID,
    ADD = 1,
    SUB,
    MUL,
    DIV,
    POW,
    LPAREN,
    RPAREN,
    INT,
    REAL,
    ID,
    ASSIGN,
    IF,
    THEN,
    SKIP,
    STOP,
    SEMI,
    LBRACE,
    RBRACE,
    EQUAL,
    EOL
  };

  // Get the next token from the input string
  virtual Lexer::Token next();

private:
  Lexer _lex;
  std::istream &_is;
  bool _first;
};

#endif