#include <iostream>
#include <string>
#include "regex_node.h"
#include "group_node.h"
#include "wildcard_node.h"
#include "character_node.h"
#include "lexer.h"

// Regex: .
RegexNode *build_single() {
  return new WildcardNode();
}

// Regex: ..
RegexNode *build_double() {
  GroupNode *node = new GroupNode();
  node->add_node(new WildcardNode());
  node->add_node(new WildcardNode());
  return node;
}

// Regex: ...
RegexNode *build_triple() {
  GroupNode *node = new GroupNode();
  node->add_node(new WildcardNode());
  node->add_node(new WildcardNode());
  node->add_node(new WildcardNode());
  return node;
}

// Regex: .-.
RegexNode *build_range() {
  GroupNode *node = new GroupNode();
  node->add_node(new WildcardNode());
  node->add_node(new CharacterNode('-'));
  node->add_node(new WildcardNode());
  return node;
}

int main() {
  enum Token { END_OF_INPUT = Lexer::END_OF_INPUT,
               INVALID = Lexer::INVALID,
               SINGLE = 1,
               DOUBLE, 
               TRIPLE,
               RANGE };
  std::string input;
  Lexer lexer;

  // add our tokens to our lexer
 // lexer.add_token(RANGE, build_range());
 // lexer.add_token(SINGLE, build_single());
  lexer.add_token(DOUBLE, build_double());
//  lexer.add_token(TRIPLE, build_triple());

  while(std::cin >> input) {
    lexer.input(input);
    Lexer::Token token;

    do {
      token = lexer.next();
      std::cout << token.tok << '\t' << token.lexeme << std::endl;
    } while(token.tok != END_OF_INPUT);
  }
}