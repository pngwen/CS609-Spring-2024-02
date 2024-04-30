// File: calculator_lexer.cpp
// Purpose: This file contains the implementation of the calculator lexer.
// Author: Robert Lowe
#include "calculator_lexer.h"

CalculatorLexer::CalculatorLexer(std::istream &_is) : _is(_is), _first(true) {
  // set up the token definitions in the lexer
  _lex.add_token(SKIP, make_regex(" |\\n"));
  _lex.add_token(ADD, make_regex("\\+"));
  _lex.add_token(SUB, make_regex("-"));
  _lex.add_token(MUL, make_regex("\\*"));
  _lex.add_token(DIV, make_regex("/"));
  _lex.add_token(POW, make_regex("^"));
  _lex.add_token(LPAREN, make_regex("\\("));
  _lex.add_token(RPAREN, make_regex("\\)"));
  _lex.add_token(INT, make_regex("[0-9]+"));
  _lex.add_token(REAL, make_regex("[0-9]+\\.[0-9]+"));
  _lex.add_token(IF, make_regex("if"));
  _lex.add_token(THEN, make_regex("then"));
  _lex.add_token(STOP, make_regex("stop"));
  _lex.add_token(ASSIGN, make_regex(":="));
  _lex.add_token(SEMI, make_regex(";"));
  _lex.add_token(LBRACE, make_regex("{"));
  _lex.add_token(RBRACE, make_regex("}"));
  _lex.add_token(EQUAL, make_regex("="));

  _lex.add_token(ID, make_regex("[a-zA-Z_][a-zA-Z0-9_]*"));
}

// Get the next token from the input string
Lexer::Token CalculatorLexer::next() {
  Lexer::Token tok;
  std::string line;

  do {
    tok = _lex.next();
    
    // handle the end of the line
    if(tok.tok == EOI) {
      getline(_is, line);
      if(not _is) { break; }
      _lex.input(line);
      tok = _lex.next();
    }
  } while (tok.tok == SKIP);

  return tok;
}