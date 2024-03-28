// File: ast_node.h
// Purpose: This file contains the definition of a pure virtual class for
//          nodes in an AST. It also contains the definition of an 
//          abstract result type.
// Author: Robert Lowe
#ifndef AST_NODE_H
#define AST_NODE_H

struct ASTResult {
  enum { VOID=0, INT, REAL} type;
  union {
    int i;
    double r;
  } value;
};

class ASTNode {
public:
  // virtual destructor
  virtual ~ASTNode();

  // evaluate the node
  virtual ASTResult eval() = 0;
};
#endif