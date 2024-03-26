// File: zero_node.cpp
// Purpose: The zero node matches the zero or more quantifier.
// Author: Robert Lowe;
// Hema Manikanta Reddy Karri, Shravan Methuku
#include "zero_node.h"
#include <string>

// construct a zero node with the node to repeat
ZeroNode::ZeroNode(RegexNode *_node) { this->_node = _node; }

// destruct a zero node
ZeroNode::~ZeroNode() { delete _node; }

// Attempt to match the string beginning at the given position.
bool ZeroNode::match(const std::string &str, size_t &pos) {
  //
  // YOUR CODE HERE
  size_t start_position = pos;

  // attempting until no more matches are found or position do not match

  while (_node->match(str, pos)) {

    if (pos == start_position) {
      break; // break out if no progress
    }
    start_position = pos; // update the initial position to current position
                          // after successful match
  }
  pos = start_position; // reset the position to original after matching zero or
                        // more matches

  return true; // since zero occurences are considered valid, always return true
}
