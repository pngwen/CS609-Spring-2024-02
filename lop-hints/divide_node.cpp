// File: divide_node.cpp
// Purpose: Implementation of the division node.
#include "divide_node.h"

ASTResult DivideNode::apply(const ASTResult &left, const ASTResult &right) {
  ASTResult result;

  // Check for division by zero
  if ((right.type == ASTResult::INT && right.value.i == 0) ||
      (right.type == ASTResult::REAL && right.value.r == 0.0)) {
    //TODO: Handle division by zero error
    result.type = ASTResult::VOID;
    return result;
  }

  // Possible type outcomes
  // INT / INT -> REAL (to handle fractional results)
  // REAL / REAL -> REAL
  // INT / REAL -> REAL
  // REAL / INT -> REAL
  if(left.type == ASTResult::INT && right.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = static_cast<double>(left.value.i) / right.value.i;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r / right.value.r;
  } else if(left.type == ASTResult::INT && right.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.i / right.value.r;
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = left.value.r / right.value.i;
  } else {
    // If the operation doesn't match any known type combination, set the type to VOID
    result.type = ASTResult::VOID;
  }

  return result;
}