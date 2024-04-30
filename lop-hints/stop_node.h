// File: stop_node.h
// Purpose: This is an AST Node which raises a stop exeption.
#ifndef STOP_NODE_H
#define STOP_NODE_H
#include "ast_node.h"
#include <exception>

class StopException : public std::exception {
  virtual const char *what();
};

class StopNode: public ASTNode {
  ASTResult eval(RefEnv *env);
};
#endif 