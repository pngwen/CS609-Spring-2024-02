// File: calculator_parser.cpp
// Purpose: This file contains the implementation of the calculator parser.

#include "calculator_parser.h"
#include "add_node.h"
#include "divide_node.h"
#include "multiply_node.h"
#include "pow_node.h"
#include "subtract_node.h"
#include "number_node.h"
#include <stdexcept>

// advance the lexer
void CalculatorParser::next() { _cur = _lexer->next(); }

// check to see if the current token matches the given token
bool CalculatorParser::has(int t) { return _cur.tok == t; }

// <Expression> ::= <Term> <Expression’>
ASTNode *CalculatorParser::parse_expression() {
  ASTNode *node = parse_term();
  return parse_expression2(node);
}

// <Expression'> ::= ADD <Term> <Expression'>
//                   | SUB <Term> <Expression'>
//                   | ""
ASTNode *CalculatorParser::parse_expression2(ASTNode *left) {
  BinopNode *result = nullptr;

  if (has(CalculatorLexer::ADD)) {
    next(); // consume ADD
    result = new AddNode();
  } else if (has(CalculatorLexer::SUB)) {
    next(); // consume SUB
    result = new SubtractNode();
  }

  if(result) {
    result->left(left);
    result->right(parse_term());
    return result;
  }

  return left; // epsilon
}

// <Term> ::= <Factor> <Term'>
ASTNode *CalculatorParser::parse_term() {
  ASTNode *node = parse_factor();
  return parse_term2(node);
}

// <Term'> ::= MUL <Factor> <Term'>
//             | DIV <Factor> <Term'>
//             | ""
ASTNode *CalculatorParser::parse_term2(ASTNode *left) {
  BinopNode *result = nullptr;

  if (has(CalculatorLexer::MUL)) {
    next(); // consume MUL 
    result = new MultiplyNode();
  } else if (has(CalculatorLexer::DIV)) {
    next(); // consume DIV 
    result = new DivideNode();
  }

  if(result) {
    result->left(left);
    result->right(parse_term());
    return result;
  }

  return left; // epsilon
}

// <Factor> ::= <Exponent> <Factor'>
ASTNode *CalculatorParser::parse_factor() {
  ASTNode *node = parse_exponent();
  return parse_factor2(node);
}

// <Factor'> ::= POW <Exponent>
//               | ""
ASTNode *CalculatorParser::parse_factor2(ASTNode *left) {
  if (has(CalculatorLexer::POW)) {
    next(); // consume POW
    PowNode *node = new PowNode();
    node->left(left);
    node->right(parse_exponent());
    return node;
  }

  return left; // epsilon
}

// <Exponent> ::= INT
//                | REAL
//                | LPAR <Expression> RPAR
ASTNode *CalculatorParser::parse_exponent() {
  if (has(CalculatorLexer::INT) || has(CalculatorLexer::REAL)) {
    ASTNode *node = new NumberNode(_cur);
    next(); 
    return node;
  } else if (has(CalculatorLexer::LPAREN)) {
    next(); // consume LPAR
    ASTNode *node = parse_expression();
    if (!has(CalculatorLexer::RPAREN)) {
      throw std::runtime_error("Expected ')'");
    }
    next(); // consume RPAR
    return node;
  } else {
    throw std::runtime_error("Unexpected token in parse_exponent()");
  }
}

ASTNode *CalculatorParser::parse(CalculatorLexer *lexer) {
  // initialize the lexer
  _lexer = lexer;
  next(); 
  
  ASTNode *result = parse_expression();
  if (_cur.tok != CalculatorLexer::EOI) {
    throw std::runtime_error("Unexpected tokens at the end of expression");
  }
  return result;
}