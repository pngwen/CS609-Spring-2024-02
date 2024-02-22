// File: range_node.h
// Purpose: Definition of a chaaracter range node class.
// Author: Robert Lowe
#ifndef RANGE_NODE_H
#define RANGE_NODE_H
#include "regex_node.h"

class RangeNode : public RegexNode {
public:
  RangeNode(char _start, char _end);

  // attempt to match the string at position pos
  virtual bool match(const std::string& str, size_t &pos);
private:
  char _start;
  char _end;
};

#endif