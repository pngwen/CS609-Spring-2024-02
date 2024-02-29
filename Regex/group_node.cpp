// File: group_node.cpp
// Purpose: Match a group of RegexNodes.
// Author: Robert Lowe
#include <string>
#include <vector>
#include "group_node.h"

//delete all the nodes in the group
GroupNode::~GroupNode()
{
  for (auto node : _nodes) {
    delete node;
  }
}

// Attempt to match the string beginning at the given position.
bool GroupNode::match(const std::string &str, size_t &pos)
{
  //save the starting position
  size_t start = pos;
  //try to match each node
  for (auto node : _nodes) {
    if (node->match(str, pos)) {
      //if node matched continue to the next node
      continue; 
    }
    //else return to the original position and return false
    else {
    pos = start;
    return false; 
    }
  }
  //all nodes in the group matched return true
  return true;
}

// Add a node to the group
void GroupNode::add_node(RegexNode *node)
{
  this->_nodes.push_back(node);
}