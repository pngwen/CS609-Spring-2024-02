// File: multiply_node.h
// Purpose: Definition of the multiply node class.
#ifndef MULTIPLY_NODE_H
#define MULTIPLY_NODE_H
#include "binop_node.h"

class MultiplyNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif