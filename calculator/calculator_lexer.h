// File: calculator_lexer.h
// Purpose: This file contains the definition of the calculator lexer.
// Author: Robert Lowe
#ifndef CALCULATOR_LEXER_H
#define CALCULATOR_LEXER_H
#include "lib/reglex.h"
#include <string.h>

class CalculatorLexer {
public:
  CalculatorLexer();

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
    ASSIGN
  };

  // set the input string to scan
  virtual void input(const std::string &_input);

  // return the input string being scanned
  virtual std::string input() const;

  // Get the next token from the input string
  virtual Lexer::Token next();

private:
  Lexer _lex;
};

#endif