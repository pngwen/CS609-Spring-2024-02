#include "equal_node.h"

ASTResult EqualNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  ASTResult result;
  result.type = ASTResult::INT;
  
  if(lhs.type != rhs.type) {
    result.value.i = 0;
    return result;
  }

  switch(lhs.type) {
    case ASTResult::INT:
      result.value.i = lhs.value.i == rhs.value.i ? 1 : 0;
      break;
    case ASTResult::REAL:
      result.value.r = lhs.value.r == rhs.value.r ? 1 : 0;
      break;
    case ASTResult::VOID:
      result.value.i = 1;
      break;
  }

  return result;
}