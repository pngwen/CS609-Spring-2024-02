// File: pow_node.cpp
// Purpose: Implementation of the exponentiation (power) node.
#include "pow_node.h"
#include <cmath> // For pow()

ASTResult PowNode::apply(const ASTResult &left, const ASTResult &right) {
  ASTResult result;

  // Exponentiation outcomes are simplified to REAL for simplicity and to accommodate
  // large or fractional powers.
  result.type = ASTResult::REAL;

  if(left.type == ASTResult::INT && right.type == ASTResult::INT) {
    result.type = ASTResult::INT;
    result.value.i = (int) std::pow(static_cast<double>(left.value.i), right.value.i);
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::REAL) {
    result.value.r = std::pow(left.value.r, right.value.r);
  } else if(left.type == ASTResult::INT && right.type == ASTResult::REAL) {
    result.value.r = std::pow(static_cast<double>(left.value.i), right.value.r);
  } else if(left.type == ASTResult::REAL && right.type == ASTResult::INT) {
    result.value.r = std::pow(left.value.r, static_cast<double>(right.value.i));
  } else {
    // Handle invalid cases or errors
    result.type = ASTResult::VOID;
  }

  return result;
}