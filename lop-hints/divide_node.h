// File: divide_node.h
// Purpose: Definition of the divide node class.
#ifndef DIVIDE_NODE_H
#define DIVIDE_NODE_H
#include "binop_node.h"

class DivideNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif