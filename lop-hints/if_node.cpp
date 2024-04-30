// File: if_node.cpp
// Purpose: This file contains the imlplementation of the IfNode class.
#include "if_node.h"

ASTResult IfNode::eval(RefEnv *env) {
  ASTResult result;
  result.type = ASTResult::VOID;

  // do the if staement
  if(left()->eval(env).is_true()) {
    result = right()->eval(env);
  }

  return result;
}


ASTResult IfNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  // Nothing to do here
  ASTResult result;
  return result;
}