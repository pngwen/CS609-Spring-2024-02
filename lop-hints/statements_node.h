// File: statements_node.h
// Purpose: An AST Node representing a sequence of statements.
#ifndef STATEMENTS_NODE
#define STATEMENTS_NODE
#include <vector>
#include "ast_node.h"

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