// File: optional_node.h
// Purpose: The optional node quantifier
// Author: Robert Lowe
#ifndef OPTIONAL_NODE_H
#define OPTIONAL_NODE_H
#include "regex_node.h"

class OptionalNode : public RegexNode {
public:
  OptionalNode(RegexNode* _node);

  // attempt to match the string at position pos
  virtual bool match(const std::string& str, size_t &pos);

private:
  RegexNode* _node;
};

#endif