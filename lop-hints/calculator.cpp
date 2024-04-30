#include <iostream>
#include <string>
#include "calculator_lexer.h"
#include "calculator_parser.h"
#include "ref_env.h"

int main() {
  CalculatorLexer lexer(std::cin);
  CalculatorParser parser;
  std::string input;
  RefEnv global;

  for(;;) {
    // get a complete statement
    std::cout << "> ";

    // set the input string to scan
    ASTNode *tree = parser.parse(&lexer);
    ASTResult result = tree->eval(&global);
    delete tree;

    // print the result
    if(result.type == ASTResult::INT) {
      std::cout << result.value.i << std::endl;
    } else if(result.type == ASTResult::REAL) {
      std::cout << result.value.r << std::endl;
    }
  }
}