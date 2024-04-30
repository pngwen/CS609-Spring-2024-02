// File: loop.h
// Purpose: A loop class which implements an infinite but stoppable loop.
#include "loop_node.h"
#include "stop_node.h"

LoopNode::LoopNode() {
  _body = nullptr;
}

// accessor and mutator for the loop body
void LoopNode::body(StatementsNode *node) {
  this->_body = node;
}


StatementsNode *LoopNode::body() {
  return this->_body;
}

// evaluate the loop
ASTResult LoopNode::eval(RefEnv *env) {
  // an infinite loop
  for(;;) {
    try {
      // evaluate the body
      body()->eval(env);
    } catch(StopException &e) {
      // if the body throws a stop exception, we're done
      break;
    }
  }

  return body()->last_result();
}