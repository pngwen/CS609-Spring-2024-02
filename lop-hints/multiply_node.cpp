// File: multiply_node.cpp
// Purpose: Implementation of the multiplication node.
#include "multiply_node.h"

ASTResult MultiplyNode::apply(const ASTResult &left, const ASTResult &right) {
  ASTResult result;

  // Possible type outputs
  // INT * INT -> INT
  // REAL * REAL -> REAL
  // INT * REAL -> REAL
  // REAL * INT -> REAL
  if(left.type == ASTResult::INT && right.type == ASTResult::INT) {
    result.type = ASTResult::INT;
    result.value.i = left.value.i * right.value.i;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r * right.value.r;
  } else if(left.type == ASTResult::INT && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.i * right.value.r;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r * right.value.i;
  } else {
    //TODO: Handle errors here
    result.type = ASTResult::VOID;
  }

  return result;
}