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