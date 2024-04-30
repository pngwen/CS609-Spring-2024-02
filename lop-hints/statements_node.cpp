#include "statements_node.h"

ASTResult StatementsNode::eval(RefEnv *env) {  
  for(ASTNode *node : _statements) {
    _last_result = node->eval(env);
  }

  return _last_result;
}

void StatementsNode::add_statement(ASTNode *node) {
  _statements.push_back(node);  
}

ASTResult StatementsNode::last_result() {
  return _last_result;
}