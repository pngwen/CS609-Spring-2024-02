// File: loop_node.h
// Purpose: A loop class which implements an infinite but stoppable loop.
#ifndef LOOP_H
#define LOOP_H
#include "ast_node.h"
#include "statements_node.h"

class LoopNode : public ASTNode {
public:
  LoopNode();

  // accessor and mutator for the loop body
  virtual void body(StatementsNode *node);
  virtual StatementsNode *body();

  // evaluate the loop
  virtual ASTResult eval(RefEnv *env);
private:
  StatementsNode *_body;
};
#endif