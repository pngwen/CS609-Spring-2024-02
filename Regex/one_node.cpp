// File: one_node.cpp
// Purpose: The one node matches the one or more quantifier.
// Author: Robert Lowe
#include <string>
#include "one_node.h"

// construct a zero node with the node to repeat
OneNode::OneNode(RegexNode *_node) {
  this->_node = _node;
}

// destruct a zero node
OneNode::~OneNode() {
  delete _node;
}

// Attempt to match the string beginning at the given position.
bool OneNode::match(const std::string &str, size_t &pos) {
  // YOUR CODE HERE
  return false;
}