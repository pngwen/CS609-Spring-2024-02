// File: wildcard_node.cpp
// Purpose: Wildcard matching
// Author: Robert Lowe
#include "wildcard_node.h"
#include <string>

// Attempt to match a wilcard pattern start position pos
bool WildcardNode::match(const std::string &str, size_t &pos) {
  if (pos >= str.length()) {
    return false;
  }

  pos++;
  return true;
}
