//File: regex_lexer.h
//Purpose: Lexer for the regex language
//Author: Robert Lowe
#ifndef REGEX_LEXER_H
#define REGEX_LEXER_H
#include "regex_node.h"
#include "lexer.h"

class RegexLexer {
public:
  //construct a regular expression lexer
  RegexLexer();

  //set the input string
  void input(const std::string &_input);

  //get the input string
  std::string input() const;

  //get the current position
  size_t position() const;

  //check to see if we are at the end of the input
  bool at_end() const;

  // The tokens emitted by this lexer can optionally contain a regex node,
  // which is the result of the lexing process. Sometimes they will not.
  enum Token {
    END_OF_INPUT = Lexer::END_OF_INPUT,
    INVALID = Lexer::INVALID,
    REGEX_NODE = 0,
    ZERO_QUANT,
    ONE_QUANT,
    OPTION_QUANT,
    OR,
    LPAREN,
    RPAREN
  };
  struct LexerToken {
    Token tok;
    std::string lexeme;
    size_t pos;
    RegexNode *node;
  };

  //get the next RegexNode, null if there is none
  LexerToken next();


private:
  Lexer _lexer;
  Lexer _spec_lexer;
};
#endif