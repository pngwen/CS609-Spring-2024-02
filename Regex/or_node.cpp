//File: or_node.cpp
//Purpose: Implements a multi-way or operator.
//Author: Robert Lowe
#include <string>
#include <vector>
#include "or_node.h"

OrNode::~OrNode() {
  for (auto node : _nodes) {
    delete node;
  }
}


// perform a greedy or match on the given string starting at pos
bool OrNode::match(const std::string &str, size_t &pos) {
  // YOUR CODE HERE
  return false;
}


// add a node to the or
void OrNode::add_node(RegexNode *node) {
  this->_nodes.push_back(node);
}