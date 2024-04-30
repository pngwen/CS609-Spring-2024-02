// File: regex_parser.h
// Purpose: Class definition for a recursive descen regex parser.
// Author: Robert Lowe
#include "regex_parser.h"
#include "regex.h"
#include <iostream>

// Constructor
RegexParser::RegexParser() {
  // nothing to do here
}

// Destructor
RegexParser::~RegexParser() {
  // nothing to do here
}

// Parse a regex string
RegexNode *RegexParser::parse(const std::string &str) {
  // start off the lexer
  _lexer.input(str);

  // get the first token
  next();

  // parse the regular expression
  return parse_regex();
}

////////////////////////////////////
// Utility Methods
////////////////////////////////////
// Display an error at the current token
void RegexParser::error(const std::string &msg) {
  std::cerr << msg << " at column " << (_cur.pos+1) << std::endl;
}

// Advance the lexer to the next token
void RegexParser::next() {
  // get the next token
  do {
    _cur = _lexer.next();
    if( _cur.tok == Lexer::INVALID ) {
      error("Invalid token");
    }
  } while (_cur.tok == Lexer::INVALID);
}

////////////////////////////////////
// Recursive Descent Methods
////////////////////////////////////

// < Regex >      ::= < Regex > < Match >
//                    | < Match >
RegexNode *RegexParser::parse_regex() {
  GroupNode *group = new GroupNode();

  while(_cur.tok != RegexLexer::END_OF_INPUT &&
        _cur.tok != RegexLexer::RPAREN) {
    group->add_node(parse_match());
  }
  
  return group;
}

// < Match >      ::= < Match-Body > (ZERO_QUANT | ONE_QUANT | OPTION_QUANT)
//                    | < Match-Body > OR < Match >
//                    | < Match-Body >
RegexNode *RegexParser::parse_match() {
  // handles all the < Match-Body > cases
  RegexNode *body = parse_match_body();

  // (ZERO_QUANT | ONE_QUANT | OPTION_QUANT)
  // | OR < Match >
  // | ""
  if( _cur.tok == RegexLexer::ZERO_QUANT) {
    next(); // consume *
    return new ZeroNode(body);
  } else if( _cur.tok == RegexLexer::ONE_QUANT) {
    next(); // consume +
    return new OneNode(body);
  } else if( _cur.tok == RegexLexer::OPTION_QUANT) {
    next(); // consume ?
    return new OptionalNode(body);
  } else if( _cur.tok == RegexLexer::OR) {
    next(); // consume |
    OrNode *or_node = new OrNode();
    or_node->add_node(body);
    or_node->add_node(parse_match());
    return or_node;
  }

  // if there is nothing after the Match-Body
  return body;
}

// < Match-Body > ::= LPAREN < Regex > RPAREN
//                    | REGEX_NODE
RegexNode *RegexParser::parse_match_body() {
  if(_cur.tok == RegexLexer::LPAREN){ 
    next(); // consume (  
    RegexNode *result = parse_regex();
    if( _cur.tok != RegexLexer::RPAREN ) {
      error("Expected )");
    } else {
      next(); // consume )
    }
    return result;
  } else if(_cur.tok == RegexLexer::REGEX_NODE) {
    RegexNode *result = _cur.node;
    next(); // consume REGEX_NODE
    return result;
  } else {
    error("Unexpected token");
    return nullptr;
  }
}