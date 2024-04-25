// File: assign_node.h
// Purpose: Definition of the assignment node class.
#ifndef ASSIGN_NODE_H
#define ASSIGN_NODE_H
#include "binop_node.h"

class AssignNode : public BinopNode {
public:
  // evaluate the assignment
  virtual ASTResult eval(RefEnv *env);

  // must have this to satisfy the pure virtual function
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};
#endif