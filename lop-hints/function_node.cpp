#include "function_node.h"
#include <stdexcept>

void FunctionNode::name(const std::string &_name) { this->_name = _name; }

std::string FunctionNode::name() { return this->_name; }

void FunctionNode::body(ASTNode *node) { this->_body = node; }

void FunctionNode::add_parameter(const std::string &param) {
  this->_param.push_back(param);
}

ASTResult FunctionNode::eval(RefEnv *env) {
  ASTResult result;

  // build the result
  result.type = ASTResult::FUNCTION;
  result.value.f = this;

  // enter ourselves in the environment
  env->declare(name());
  *(env->lookup(name())) = result;

  return result;
}

ASTResult FunctionNode::call(RefEnv *env, std::vector<ASTResult> &args) {
  if (args.size() != _param.size()) {
    throw std::runtime_error("Wrong number of arguments for function " +
                             name());
  }

  // create the local environment
  RefEnv *local_env = new RefEnv(env);

  // bind the parameters to the local environment
  for (int i = 0; i < args.size(); i++) {
    local_env->declare(_param[i]);
    *(local_env->lookup(_param[i])) = args[i];
  }

  // run the function and return the result
  ASTResult result = _body->eval(local_env);
  delete local_env;
  return result;
}