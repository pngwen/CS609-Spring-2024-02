#include "stop_node.h"

const char *StopException::what() {
  return "Loopless stop encountered.";
}

ASTResult StopNode::eval(RefEnv *env) {
  throw StopException();  
}