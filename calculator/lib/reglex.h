// File: regex_node.h
// Purpose: Abstract class for a regex matching state
// Author: Robert Lowe
#ifndef REGEX_NODE_H
#define REGEX_NODE_H
#include <string>

class RegexNode
{
public:
  // virtual destructor
  virtual ~RegexNode();

  // Attempt to match the string beginning at the given position.
  // Parameters:
  //   str - The string to match
  //   pos - The position in the string to match
  // Returns:
  //   true if the string beginning at the position pos matches
  //   false if the character is not matched
  //   Also, this function should update the position according to point
  //   to the next character after the match.
  virtual bool match(const std::string &str, size_t &pos)=0;
};

#endif
// File: lexer.h
// Purpose: Definition of a general purpose lexer class. This lexer 
//          performs lexical analysis on a given input string.
// Author: Robert Lowe
#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <vector>
#include <utility>


class Lexer {
public:
  // construct a lexer with an empty string to scan
  Lexer();

  // construct a lexer to scan the given input string
  Lexer(const std::string& input);

  // destroy the lexer and deallocate all the RegexNodes
  virtual ~Lexer();

  // set the input string to scan
  void input(const std::string& _input);

  // retrieve the input string to scan
  std::string input() const;

  // return true if the lexer is at the end of the input
  bool at_end() const;

  // return the current position of the lexer
  int position() const;

  // The tokens emitted by the lexer
  // Note there are two pre-defined tokens:
  //   - END_OF_INPUT  -1
  //   - INVALID       -2 
  // User defined tokens should be positive.
  struct Token {
    int tok;             // numeric token
    size_t pos;          // position of the token in the input string
    std::string lexeme;  // matched lexeme
  };
  static const int END_OF_INPUT = -1;
  static const int INVALID = -2;

  // Add a new token to the lexer
  void add_token(int tok, RegexNode *pattern);

  // Get the next token from the input string
  Token next();

private:
  std::string _input;
  size_t _pos;
  std::vector<std::pair<int, RegexNode*>> _tokens;
};
#endif// RegexNode class prototype
class RegexNode;

RegexNode* make_regex(const std::string &str);