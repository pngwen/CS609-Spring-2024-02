// File: add_node.cpp
// Purpose: Implementation of the addition node.
#include "add_node.h"

ASTResult AddNode::apply(const ASTResult &left, const ASTResult &right) {
  ASTResult result;
  
  // Possible type outputs (Attribute Grammar)
  // INT + INT -> INT     .i + .i
  // REAL + REAL -> REAL   .r + .r
  // INT + REAL -> REAL    .i + .r
  // REAL + INT -> REAL    .r + .i
  if(left.type == ASTResult::INT && right.type == ASTResult::INT) {
    result.type = ASTResult::INT;
    result.value.i = left.value.i + right.value.i;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r + right.value.r;
  } else if(left.type == ASTResult::INT && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.i + right.value.r;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r + right.value.i;
  } else {
    //TODO: Handle errors here
    result.type = ASTResult::VOID;
  }

  return result;
}