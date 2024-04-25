// File: subtract_node.h
// Purpose: Definition of the subtract node class.
#ifndef SUBTRACT_NODE_H
#define SUBTRACT_NODE_H
#include "binop_node.h"

class SubtractNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif