// File: regex_parser.h
// Purpose: Class definition for a recursive descen regex parser.
// Author: Robert Lowe
#ifndef REGEX_PARSER_H
#define REGEX_PARSER_H
#include "regex_lexer.h"
#include "regex_node.h"
#include <string>
class RegexParser {
public:
  // Constructor
  RegexParser();

  // Destructor
  virtual ~RegexParser();

  // Parse a regex string
  virtual RegexNode *parse(const std::string &str);

private:
  // The lexer and the current token
  RegexLexer _lexer;
  RegexLexer::LexerToken _cur;

  ////////////////////////////////////
  // Utility Methods
  ////////////////////////////////////
  // Display an error at the current token
  void error(const std::string &msg);

  // Adcance the lexer to the next token
  void next();

  ////////////////////////////////////
  // Recursive Descent Methods
  ////////////////////////////////////

  // < Regex >      ::= < Regex > < Match >
  //                    | < Match >
  RegexNode *parse_regex();

  // < Match >      ::= < Match-Body > (ZERO_QUANT | ONE_QUANT | OPTION_QUANT)
  //                    | < Match-Body > OR < Match >
  //                    | < Match-Body >
  RegexNode *parse_match();

  // < Match-Body > ::= LPAREN < Regex > RPAREN
  //                    | REGEX_NODE
  RegexNode *parse_match_body();
};

#endif