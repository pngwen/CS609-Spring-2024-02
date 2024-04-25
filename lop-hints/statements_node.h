#ifndef STATEMENTS_NODE_H
#define STATEMENTS_NODE_H
#include "ast_node.h"
#include <vector>

class StatementsNode : public ASTNode {
public:
  virtual ASTResult eval(RefEnv *env);
  virtual void add_statement(ASTNode *node);
  virtual ASTResult last_result();

private:
  std::vector<ASTNode *> _statements;
  ASTResult _last_result;
};
#endif