// File: character_node.cpp
// Purpose: A node which matches a single character.
// Author: Robert Lowe  
#include <string>
#include "character_node.h"

// construct a character node
CharacterNode::CharacterNode(char _c)
{
  this->_c = _c;
}

// Attempt to match the string beginning at the given position.
bool CharacterNode::match(const std::string &str, size_t &pos) {
  if (pos < str.size() && str[pos] == _c) {
    pos++;
    return true;
  } 

  return false;
}