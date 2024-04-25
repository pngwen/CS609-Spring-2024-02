// File: ref_env.cpp
// Purpose: Implementation of our reference environment.
#include "ref_env.h"

// constructors
RefEnv::RefEnv() : RefEnv(nullptr) { }

RefEnv::RefEnv(RefEnv* _parent) {
  parent(_parent);
}

// destructor
RefEnv::~RefEnv() { }

// Provide access to the values in the environment
// Return a pointer to the value if it exists, otherwise return NULL
ASTResult *RefEnv::lookup(const std::string &name) {
  // check for the name in the local environment
  if(_env.find(name) != _env.end()) {
    return &_env[name];
  }

  // if there is no parent, we are done
  if(parent() == nullptr) {
    return nullptr;
  }

  // otherwise, look in the parent
  return parent()->lookup(name);
}

// Declare a new variable in the environment
void RefEnv::declare(const std::string &name) {
  // always declare locally
  _env[name] = ASTResult();
  _env[name].type = ASTResult::VOID;
}

// Access the parent
RefEnv *RefEnv::parent() {
  return _parent;
}

// Set the parent
void RefEnv::parent(RefEnv *_parent) {
  this->_parent = _parent;
}