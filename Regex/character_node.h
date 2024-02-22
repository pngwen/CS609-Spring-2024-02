// File: character_node.h
// Purpose: A node which matches a single character.
// Author: Robert Lowe
#ifndef CHARACTER_NODE_H
#define CHARACTER_NODE_H
#include <string>
#include "regex_node.h"

class CharacterNode : public RegexNode
{
public:
  // construct a character node
  CharacterNode(char _c);

  // Attempt to match the string beginning at the given position.
  virtual bool match(const std::string &str, size_t &pos);

private:
  char _c;
};

#endif