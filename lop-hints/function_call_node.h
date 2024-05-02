#ifndef FUNCTION_CALL_NODE_H
#define FUNCTION_CALL_NODE_H

#include "ast_node.h"
#include <string>
#include <vector>

class FunctionCallNode : public ASTNode {
public:
    // Destructor
    virtual ~FunctionCallNode();

    // set the function name
    virtual void name(const std::string &_name);

    // Add an argument to the function call
    void add_argument(ASTNode* argument);

    // Inherited from ASTNode, evaluates the function call
    virtual ASTResult eval(RefEnv *env) override;

private:
    std::string _functionName;                // The name of the function being called
    std::vector<ASTNode*> _arguments;         // The arguments to the function
};

#endif // FUNCTION_CALL_NODE_H