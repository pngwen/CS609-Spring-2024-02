// File: calculator_parser.h
// Purpose: This file contains the definition of the calculator parser.
// Author: Robert Lowe
#ifndef CALCULATOR_PARSER_H
#define CALCULATOR_PARSER_H
#include "ast_node.h"
#include "calculator_lexer.h"

class CalculatorParser {
public:
  ASTNode *parse(CalculatorLexer *_lexer);

private:
  CalculatorLexer *_lexer;
  Lexer::Token _cur;

  // advance the lexer
  void next();

  // check to see if the current token matches the given token
  bool has(int t);

  //< Expression > ::= < Term > < Expression' >
  ASTNode *parse_expression();

  //< Expression' >::= ADD < Term > < Expression' >
  //                   | SUB < Term > < Expression' >
  //                   | ""
  ASTNode *parse_expression2(ASTNode *left);
                     
  //< Term >       ::= < Factor > < Term' > 
  ASTNode *parse_term();

  //< Term' >      ::= MUL < Factor > < Term' >
  //                   | DIV < Factor > < Term' >
  //                   | ""
  ASTNode *parse_term2(ASTNode *left);
  
  //< Factor >     ::= < Exponent > < Factor' >
  ASTNode *parse_factor();

  //< Factor' >    ::= POW < Exponent >
  //                   | ""
  ASTNode *parse_factor2(ASTNode *left);

  //< Exponent >   ::= INT 
  //                   | REAL
  //                   | LPAR < Expression > RPAR
  ASTNode *parse_exponent();
};

#endif