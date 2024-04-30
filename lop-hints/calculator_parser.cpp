// File: calculator_parser.cpp
// Purpose: This file contains the implementation of the calculator parser.

#include "calculator_parser.h"
#include "add_node.h"
#include "divide_node.h"
#include "multiply_node.h"
#include "pow_node.h"
#include "subtract_node.h"
#include "number_node.h"
#include "ref_node.h"
#include "assign_node.h"
#include "if_node.h"
#include "stop_node.h"
#include "statements_node.h"
#include "loop_node.h"
#include "equal_node.h"
#include <stdexcept>

// advance the lexer
void CalculatorParser::next() { _cur = _lexer->next(); }

// check to see if the current token matches the given token
bool CalculatorParser::has(int t) { return _cur.tok == t; }


// < Expression > ::= < Ref > < Expression' > 
//                    | < If >
//                    | < Stop >
//                    | < Sum >                       
//                    | < Loop >
ASTNode *CalculatorParser::parse_expression() {
  if(has(CalculatorLexer::ID)) {
    ASTNode *left = parse_ref();
    return parse_expression2(left);
  } else if(has(CalculatorLexer::IF)) {
    return parse_if();
  } else if(has(CalculatorLexer::STOP)) {
    next();
    return new StopNode();
  } else if(has(CalculatorLexer::LBRACE)) {
    return parse_loop();
  }
  
  return parse_sum();
}

// < Expression' > ::= ASSIGN < Expression >
//                     | < Sum' >
ASTNode *CalculatorParser::parse_expression2(ASTNode *left) {
  if(has(CalculatorLexer::ASSIGN)) {
    next();
    AssignNode *node = new AssignNode();
    node->left(left);
    node->right(parse_expression());
    return node;
  }

  return parse_sum2(left);
}

// < Sum > ::= < Term > < Sum’ >
ASTNode *CalculatorParser::parse_sum() {
  ASTNode *node = parse_term();
  return parse_sum2(node);
}

// < Sum' > ::= ADD <Term> <Sum'>
//                   | SUB <Term> <Sum'>
//                   | EQUAL < Term > < Sum' >
//                   | ""
ASTNode *CalculatorParser::parse_sum2(ASTNode *left) {
  BinopNode *result = nullptr;

  if (has(CalculatorLexer::ADD)) {
    next(); // consume ADD
    result = new AddNode();
  } else if (has(CalculatorLexer::SUB)) {
    next(); // consume SUB
    result = new SubtractNode();
  } else if (has(CalculatorLexer::EQUAL)) {
    next(); // consume EQUAL
    result = new EqualNode();
  }

  if(result) {
    result->left(left);
    result->right(parse_term());
    return parse_sum2(result);
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
    return parse_term2(result);
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
//                | < Ref >
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
    return parse_ref();
  }
}

//< Ref >        ::= ID
ASTNode *CalculatorParser::parse_ref() {
  // detect an error
  if(!has(CalculatorLexer::ID)) {
    throw std::runtime_error("Expected ID");
  }

  ASTNode *node = new RefNode(_cur.lexeme);
  next();
  return node;
}

ASTNode *CalculatorParser::parse(CalculatorLexer *lexer) {
  // initialize the lexer
  _lexer = lexer;
  next(); 
  
  ASTNode *result = parse_statements();
  if (_cur.tok != CalculatorLexer::EOI && _cur.tok != CalculatorLexer::EOL) {
    throw std::runtime_error("Unexpected tokens at the end of expression");
  }

  return result;
}

// if condition then statement
ASTNode *CalculatorParser::parse_if() {
  if(has(CalculatorLexer::IF)) {
    next(); // consume IF
  } else {
    throw std::runtime_error("Expected IF");
  }

  ASTNode *cond = parse_expression();
  
  if(has(CalculatorLexer::THEN)) {
    next(); // consume THEN 
  } else {
    throw std::runtime_error("Expected THEN");
  }

  ASTNode *then = parse_expression();

  IfNode *node = new IfNode();
  node->left(cond);
  node->right(then);

  return node;
}

// collection of statements
ASTNode *CalculatorParser::parse_statements() {
  bool consume = false;
  StatementsNode *node = new StatementsNode();

  do {
    if(consume) { next(); }
    node->add_statement(parse_expression());
    consume = true;
  } while(has(CalculatorLexer::SEMI));

  return node;
}

// a loop consisting of { statements }
ASTNode *CalculatorParser::parse_loop() {
  if(has(CalculatorLexer::LBRACE)) {
    next();
  } else {
    throw std::runtime_error("Expected {");
  }
  
  StatementsNode *body = (StatementsNode*) parse_statements();
  
  if(has(CalculatorLexer::RBRACE)) {
    next();
  } else {
    throw std::runtime_error("Expected }");
  }

  // build the loop node
  LoopNode *node = new LoopNode();
  node->body(body);
  return node;
}