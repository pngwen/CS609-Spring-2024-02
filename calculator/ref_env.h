// File: ref_env.h
// Purpose: This file contains the definition of the reference environment
#ifndef REF_ENV_H
#define REF_ENV_H
#include <map>
#include <string>
#include "ast_node.h"

struct ASTResult;

class RefEnv {
public:
  // constructors
  RefEnv();
  RefEnv(RefEnv* _parent);

  // destructor
  virtual ~RefEnv();

  // Provide access to the values in the environment
  // Return a pointer to the value if it exists, otherwise return NULL
  virtual ASTResult *lookup(const std::string &name);

  // Declare a new variable in the environment
  virtual void declare(const std::string &name);

  // Access the parent
  virtual RefEnv *parent();

  // Set the parent
  virtual void parent(RefEnv *_parent);

private:
  // The map of variable names to values
  std::map<std::string, ASTResult> _env;

  // The parent environment
  RefEnv *_parent;
};
#endif