// File: wildcard_node.h
// Purpose: Wildcard matching
// Author: Robert Lowe
#ifndef WILDCARD_NODE_H
#define WILDCARD_NODE_H
#include "regex_node.h"
#include <string>

class WildcardNode : public RegexNode {
public:

  // Attempt to match a wilcard pattern start position pos
  virtual bool match(const std::string &str, size_t &pos);
};
#endif