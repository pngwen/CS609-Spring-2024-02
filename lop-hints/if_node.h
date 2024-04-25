#include "binop_node.h"
#ifndef IF_NODE_H
#define IF_NODE_H

class IfNode : public BinopNode {
public:
  virtual ASTResult eval(RefEnv *env);
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};

#endif