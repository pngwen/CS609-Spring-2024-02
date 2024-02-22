// File: inverse_node.h
// Purpose: The inverse node
// Author: Robert Lowe
#ifndef INVERSE_NODE_H
#define INVERSE_NODE_H
#include "regex_node.h"

class InverseNode : public RegexNode {
public:
  InverseNode(RegexNode* _node);

  // attempt to match the string at position pos
  virtual bool match(const std::string& str, size_t &pos);

private:
  RegexNode* _node;
};

#endif