// File: zero_node.cpp
// Purpose: The zero node matches the zero or more quantifier.
// Author: Robert Lowe
#include <string>
#include "zero_node.h"

// construct a zero node with the node to repeat
ZeroNode::ZeroNode(RegexNode *_node) {
  this->_node = _node;
}

// destruct a zero node
ZeroNode::~ZeroNode() {
  delete _node;
}

// Attempt to match the string beginning at the given position.
bool ZeroNode::match(const std::string &str, size_t &pos) {
  
  // YOUR CODE HERE
  
  return false;
}