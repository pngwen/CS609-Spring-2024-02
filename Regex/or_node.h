//File: or_node.h
//Purpose: Implements a multi-way or operator.
//Author: Robert Lowe
#ifndef OR_NODE_H
#define OR_NODE_H
#include <string>
#include <vector>
#include "regex_node.h"

class OrNode : public RegexNode {
public:
  ~OrNode();

  // perform a greedy or match on the given string starting at pos
  virtual bool match(const std::string &str, size_t &pos);

  // add a node to the or
  virtual void add_node(RegexNode *node);

private:
  std::vector<RegexNode *> _nodes;
};

#endif