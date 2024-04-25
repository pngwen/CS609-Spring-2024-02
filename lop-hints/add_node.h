// File: add_node.h
// Purpose: Definition of the add node class.
#ifndef ADD_NODE_H
#define ADD_NODE_H
#include "binop_node.h"

class AddNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif