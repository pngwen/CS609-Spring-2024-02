#include "function_call_node.h"
#include "function_node.h"
#include "ref_env.h"
#include <stdexcept>

FunctionCallNode::~FunctionCallNode() {
    // delete all the argument nodes
    for (auto &arg : _arguments) {
        delete arg;
    }
}

void FunctionCallNode::name(const std::string &_name) {
    this->_functionName = _name;
}

void FunctionCallNode::add_argument(ASTNode* argument) {
    this->_arguments.push_back(argument);
}

ASTResult FunctionCallNode::eval(RefEnv *env) {
    // Look up the function in the environment
    ASTResult *fun = env->lookup(this->_functionName);

    // Ensure the result is a function
    if (fun == nullptr || fun->type != ASTResult::FUNCTION) {
        throw std::runtime_error(this->_functionName + " is not a function");
    }

    // Evaluate arguments and collect their results
    std::vector<ASTResult> argResults;
    for (ASTNode* arg : this->_arguments) {
        ASTResult result = arg->eval(env);
        argResults.push_back(result);
    }

    // call the function
    return fun->value.f->call(env, argResults);
}