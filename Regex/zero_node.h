// File: zero_node.h
// Purpose: The zero node matches the zero or more quantifier.
// Author: Robert Lowe
#ifndef ZERO_NODE_H
#define ZERO_NODE_H
#include <string>
#include "regex_node.h"

class ZeroNode : public RegexNode {
public:
  // construct a zero node with the node to repeat
  ZeroNode(RegexNode *_node);

  // destruct a zero node
  ~ZeroNode();

  // Attempt to match the string beginning at the given position.
  virtual bool match(const std::string &str, size_t &pos);

private:
  // the node to repeat
  RegexNode *_node;
};
#endif