#include "binop_node.h"

class EqualNode : public BinopNode {
public:
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs);
};