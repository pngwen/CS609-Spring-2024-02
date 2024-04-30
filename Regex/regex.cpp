#include <iostream>
#include <string>
#include "regex.h"
#include "regex_parser.h"

int main() {
  RegexParser parser;
  RegexNode *regex;
  std::string s;

  // get the regular expression from the user
  std::cout << "Enter a regular expression: ";
  std::getline(std::cin, s);
  regex = parser.parse(s);

  // attempt matches
  for(;;) {
    // get the string
    std::cout << "> ";
    std::getline(std::cin, s);
    if(!std::cin) break;

    // attempt the match
    size_t pos = 0;
    if (regex->match(s, pos) && pos == s.length()) {
      std::cout << "Match!" << std::endl;
    } else {
      std::cout << "No match." << std::endl;
    }
  }
}