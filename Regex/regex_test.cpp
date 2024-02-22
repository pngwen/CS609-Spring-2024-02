#include <iostream>
#include <string>
#include "group_node.h"
#include "character_node.h"
#include "zero_node.h"
#include "one_node.h"
#include "optional_node.h"
#include "or_node.h"
#include "range_node.h"
#include "inverse_node.h"

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input, RegexNode *regex);

// Construct regular expression (ab)*ac
RegexNode* construct_regex1();

// Construct regular expression (ab)+ac
RegexNode* construct_regex2();

// Construct regular expression (a|(aa))b
RegexNode* construct_regex3();

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode* construct_regex4();

// Construct the regular expression [a-zA-Z]+
RegexNode * construct_regex5();

// Construct the regular expression "[^"]*"
RegexNode * construct_regex6();


int main() {
  std::string input_str;
  RegexNode *regex1 = construct_regex1();
  RegexNode *regex2 = construct_regex2();
  RegexNode *regex3 = construct_regex3();
  RegexNode *regex4 = construct_regex4();
  RegexNode *regex5 = construct_regex5();
  RegexNode *regex6 = construct_regex6();

  while(std::cin) {
    // get the user input
    std::cout << "Input> ";
    getline(std::cin, input_str);
    if(!std::cin) continue;

    // print the result
    print_match("(ab)*ac", input_str, regex1);
    print_match("(ab)+ac", input_str, regex2);
    print_match("(a|(aa))b", input_str, regex3);
    print_match("[0-9]+(\\.[0-9]+)?", input_str, regex4);
    print_match("[a-zA-Z]+", input_str, regex5);
    print_match("\"[^\"]*\"", input_str, regex6);
  }

  //cleanup
  delete regex1;
  delete regex2;
  delete regex3;
  delete regex4;
  delete regex5;
  delete regex6;
}


// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input, RegexNode *regex) {
    size_t pos = 0;

    std::cout << label << ": ";
    if(regex->match(input, pos) && pos == input.length()) {
      std::cout << "Match!" << std::endl;
    } else {
      std::cout << "No match." << std::endl;
    }
}


// Construct regular expression (ab)*ac
RegexNode* construct_regex1()
{
  // create the result
  GroupNode *regex = new GroupNode();

  //create ab node
  GroupNode *ab = new GroupNode();
  ab->add_node(new CharacterNode('a'));
  ab->add_node(new CharacterNode('b'));

  //create the star quantifier
  ZeroNode *star = new ZeroNode(ab);
  regex->add_node(star);

  //set up the main expression
  regex->add_node(new CharacterNode('a'));
  regex->add_node(new CharacterNode('c'));

  return regex;
}


// Construct regular expression (ab)+ac
RegexNode* construct_regex2() {
  // create the result
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE

  return regex;
}


// Construct regular expression (a|(aa))b
RegexNode* construct_regex3() {
  // create the result
  GroupNode *regex = new GroupNode();
  
  // YOUR CODE HERE
  
  return regex;
}



// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode* construct_regex4() {
  GroupNode *regex = new GroupNode(); 

  // YOUR CODE HERE
  
  return regex;
}


// Construct the regular expression [a-zA-Z]+
RegexNode * construct_regex5()
{
  GroupNode *regex = new GroupNode();  

  // YOUR CODE HERE
  
  return regex;
}


// Construct the regular expression "[^"]*"
RegexNode * construct_regex6() 
{
  GroupNode *regex = new GroupNode();  

  // YOUR CODE HERE
  
  return regex;
}


