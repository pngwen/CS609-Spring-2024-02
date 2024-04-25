// File: ref_node.cpp
// Purpose: Implementation of the reference node.
#include <iostream>
#include "ref_node.h"

// Constructor and Destructor
RefNode::RefNode(const std::string &_name) {
  this->_name = _name;  
}

RefNode::~RefNode() {
  
}

// Evaluate the node
ASTResult RefNode::eval(RefEnv *env) {
  ASTResult *result = env->lookup(this->_name);
  
  if(!result) {
    //TODO: Better error handling
    std::cerr << "Error: Variable " << this->_name << " not found." << std::endl;
    ASTResult error;
    error.type = ASTResult::VOID;
    return error;
  }

  return *result;
}

// Assign a value to the reference
void RefNode::assign(RefEnv *env, ASTResult _value) {
  // the logic of local declaration
  // if not defined, add it and then assign a value
  ASTResult *result = env->lookup(this->_name);
  if(!result) {
    env->declare(this->_name);
    result = env->lookup(this->_name);
  }

  // assign the value
  *result = _value;
}