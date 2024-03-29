// File: pow_node.h
// Purpose: Definition of the pow (exponent) node class.
#ifndef POW_NODE_H
#define POW_NODE_H
#include "binop_node.h"

class PowNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif