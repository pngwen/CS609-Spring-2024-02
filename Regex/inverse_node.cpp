// File: inverse_node.cpp
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "inverse_node.h"

InverseNode::InverseNode(RegexNode* _node)
{
  this->_node = _node;  
}


// attempt to match the string at position pos
bool InverseNode::match(const std::string& str, size_t &pos)
{
  // YOUR CODE HERE
  return false;
}