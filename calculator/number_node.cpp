// File: number_node.cpp
// Purpose: Implementation of the number node.
#include "number_node.h"
#include <string>

NumberNode::NumberNode(const Lexer::Token &token) {
  if(token.tok == CalculatorLexer::INT) {
    _value.type = ASTResult::INT;
    _value.value.i = std::stoi(token.lexeme);
  } else if(token.tok == CalculatorLexer::REAL) {
    _value.type = ASTResult::REAL;
    _value.value.r = std::stof(token.lexeme);
  } else {
    _value.type = ASTResult::VOID;
  }
}

NumberNode::~NumberNode() {}

ASTResult NumberNode::eval() {
    return _value;
}