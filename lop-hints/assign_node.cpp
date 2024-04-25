// File: assign_node.cpp
// Purpose: Implementation of the assignment node.
#include "assign_node.h"
#include "ref_node.h"

// evaluate the assignment
ASTResult AssignNode::eval(RefEnv *env) {
  RefNode *ref = (RefNode *) left();
  ref->assign(env, right()->eval(env));
  return ref->eval(env);
}

// must have this to satisfy the pure virtual function
ASTResult AssignNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  // This function is never called
  return ASTResult();
}