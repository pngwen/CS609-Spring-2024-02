// File: one_node.h
// Purpose: The one node matches the one or more quantifier.
// Author: Robert Lowe
#ifndef ONE_NODE_H
#define ONE_NODE_H
#include <string>
#include "regex_node.h"

class OneNode : public RegexNode {
public:
  // construct a zero node with the node to repeat
  OneNode(RegexNode *_node);

  // destruct a zero node
  ~OneNode();

  // Attempt to match the string beginning at the given position.
  virtual bool match(const std::string &str, size_t &pos);

private:
  // the node to repeat
  RegexNode *_node;
};
#endif