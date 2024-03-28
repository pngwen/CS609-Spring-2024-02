// File: binop_node.h
// Purpose: This file contains an abstract class which represents a
//          binary operation node in an AST.
// Author: Robert Lowe
#ifndef BINOP_NODE_H
#define BINOP_NODE_H
#include "ast_node.h"

class BinopNode : public ASTNode {
public:
  // constructor
  BinopNode();

  // virtual destructor
  virtual ~BinopNode();

  // Set the left node
  virtual void left(ASTNode* node);

  // Set the right node
  virtual void right(ASTNode* node);

  // Return the left node
  virtual ASTNode* left();

  // Return the right node
  virtual ASTNode* right();

  // apply the operator to the two operands
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) = 0;

  // evaluate the node
  virtual ASTResult eval();

protected:
  ASTNode *_left;
  ASTNode *_right;
};

#endif