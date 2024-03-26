// File: one_node.cpp
// Purpose: The one node matches the one or more quantifier.
// Author: Robert Lowe
//Edula Ranga Venkata Sai Kumar Reddy, Naresh Kollu, Sai Manideep Pellimari
#include "one_node.h"
#include <string>

// construct a zero node with the node to repeat
OneNode::OneNode(RegexNode *_node) { this->_node = _node; }

// destruct a zero node
OneNode::~OneNode() { delete _node; }

// Attempt to match the string beginning at the given position.
bool OneNode::match(const std::string &str, size_t &pos) {
  size_t initialPos = pos;

  // Attempt to match the node at least once
  if (!_node->match(str, pos))
    return false;

  // Continue attempting to match the node zero or more times
  while (_node->match(str, pos) && pos < str.length()) {
    // Increment position if successful match
    pos++;
  }
  return (pos > initialPos);
}