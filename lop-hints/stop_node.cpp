#include "stop_node.h"

const char *StopException::what() const throw() {
  return "Uncaught stop exception";  
}

ASTResult StopNode::eval(RefEnv *env) {
  throw StopException();
}