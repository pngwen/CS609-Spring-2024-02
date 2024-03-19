// File: or_node.cpp
// Purpose: Implements a multi-way or operator.
// Author: Robert Lowe
#include "or_node.h"
#include <string>
#include <vector>

OrNode::~OrNode() {
  for (auto node : _nodes) {
    delete node;
  }
}

// perform a greedy or match on the given string starting at pos
bool OrNode::match(const std::string &str, size_t &pos) {
  for (auto node : _nodes) {
    size_t start_pos = pos;
    if (node->match(str, pos)) {
      return true;
    }
    pos = start_pos;
  }
  return false;
}

// add a node to the or
void OrNode::add_node(RegexNode *node) { this->_nodes.push_back(node); }