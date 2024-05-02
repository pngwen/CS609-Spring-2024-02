#ifndef FUNCTION_NODE_H
#define FUNCTION_NODE_H
#include "ast_node.h"
#include <string>
#include <vector>

class FunctionNode : public ASTNode {
public:
  // set the name of the function
  virtual void name(const std::string &_name);

  // get the name of the function
  virtual std::string name();

  // set the body of the function
  virtual void body(ASTNode *node);

  // add a parameter to the function
  virtual void add_parameter(const std::string &p);

  // evaluate the function - insert itself into the RefEnv
  virtual ASTResult eval(RefEnv *env);

  // Call the function
  virtual ASTResult call(RefEnv *env, std::vector<ASTResult> &args);
private:
  std::string _name;
  std::vector<std::string> _param;
  ASTNode *_body;
};

#endif