#include "if_node.h"

ASTResult IfNode::eval(RefEnv *env) {
  ASTResult result;
  result.type = ASTResult::VOID; 
  
  if(left()->eval(env).is_true()) {
    result = right()->eval(env);
  }

  return result;
}

ASTResult IfNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  return ASTResult();
}
