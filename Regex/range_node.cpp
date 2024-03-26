// File: range_node.cpp
// Purpose: Definition of a chaaracter range node class.
// Author: Robert Lowe

#include "range_node.h"
#include <algorithm>

RangeNode::RangeNode(char _start, char _end) {
  this->_start = std::min(_start, _end);
  this->_end = std::max(_start, _end);
}

// attempt to match the string at position pos
bool RangeNode::match(const std::string &str, size_t &pos) {
  // YOUR CODE HERE
  if (pos >= str.length()) {
    return false;
  }
  char c = str[pos];
  if (c >= _start && c <= _end) {
    ++pos;
    return true;
  }
  return false;
}