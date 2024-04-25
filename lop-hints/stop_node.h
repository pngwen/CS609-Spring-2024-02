#ifndef STOP_NODE_H
#define STOP_NODE_H
#include <exception>
#include "ast_node.h"

class StopException : public std::exception {
public:
  virtual const char *what() const throw();
};

class StopNode : public ASTNode {
public:
  virtual ASTResult eval(RefEnv *env);
};

#endif