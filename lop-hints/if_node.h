// File: if_node.h
// Purpose: This file contains the definition of the IfNode class.
#ifndef IF_NODE_H
#define IF_NODE_H
#include "binop_node.h"

class IfNode: public BinopNode {
public:
  ASTResult eval(RefEnv *env);
  ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};
#endif