// File: binop_node.cpp
// Purpose: Implementation of the binary operation node.
#include "binop_node.h"

// Constructor initializes left and right pointers to nullptr
BinopNode::BinopNode() : _left(nullptr), _right(nullptr) {}

// Virtual destructor
BinopNode::~BinopNode() {
  if(_left) {
    delete _left;
  }
  
  if(_right ) {
    delete _right;
  }
}

// Set the left node
void BinopNode::left(ASTNode *node) { _left = node; }

// Set the right node
void BinopNode::right(ASTNode *node) { _right = node; }

// Return the left node
ASTNode *BinopNode::left() { return _left; }

// Return the right node
ASTNode *BinopNode::right() { return _right; }

// Evaluate the node
ASTResult BinopNode::eval() {
  // First, evaluate the left and right child nodes
  ASTResult leftResult = left()->eval();
  ASTResult rightResult = right()->eval();
  
  // Then, apply the operation to the results of the left and right nodes.
  // This relies on derived classes implementing the 'apply' method.
  return apply(leftResult, rightResult);
}
