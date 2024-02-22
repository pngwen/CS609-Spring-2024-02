// File: group_node.h
// Purpose: Match a group of RegexNodes.
// Author: Robert Lowe
#ifndef GROUP_NODE_H
#define GROUP_NODE_H
#include <string>
#include <vector>
#include "regex_node.h"

class GroupNode : public RegexNode {
public:
  //delete all the nodes in the group
  virtual ~GroupNode();

  // Attempt to match the string beginning at the given position.
  virtual bool match(const std::string &str, size_t &pos);

  // Add a node to the group
  virtual void add_node(RegexNode *node);

private:
  std::vector<RegexNode *> _nodes;
};

#endif 