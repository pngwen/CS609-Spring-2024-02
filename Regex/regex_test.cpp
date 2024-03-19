#include "character_node.h"
#include "group_node.h"
#include "inverse_node.h"
#include "one_node.h"
#include "optional_node.h"
#include "or_node.h"
#include "range_node.h"
#include "zero_node.h"
#include <iostream>
#include <string>

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex);

// Construct regular expression (ab)*ac
RegexNode *construct_regex1();

// Construct regular expression (ab)+ac
RegexNode *construct_regex2();

// Construct regular expression (a|(aa))b
RegexNode *construct_regex3();

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex4();

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex5();

// Construct the regular expression "[^"]*"
RegexNode *construct_regex6();

int main() {
  std::string input_str;
  RegexNode *regex1 = construct_regex1();
  RegexNode *regex2 = construct_regex2();
  RegexNode *regex3 = construct_regex3();
  RegexNode *regex4 = construct_regex4();
  RegexNode *regex5 = construct_regex5();
  RegexNode *regex6 = construct_regex6();

  while (std::cin) {
    // get the user input
    std::cout << "Input> ";
    getline(std::cin, input_str);
    if (!std::cin)
      continue;

    // print the result
    print_match("(ab)*ac", input_str, regex1);
    print_match("(ab)+ac", input_str, regex2);
    print_match("(a|(aa))b", input_str, regex3);
    print_match("[0-9]+(\\.[0-9]+)?", input_str, regex4);
    print_match("[a-zA-Z]+", input_str, regex5);
    print_match("\"[^\"]*\"", input_str, regex6);
  }

  // cleanup
  delete regex1;
  delete regex2;
  delete regex3;
  delete regex4;
  delete regex5;
  delete regex6;
}

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex) {
  size_t pos = 0;

  std::cout << label << ": ";
  if (regex->match(input, pos) && pos == input.length()) {
    std::cout << "Match!" << std::endl;
  } else {
    std::cout << "No match." << std::endl;
  }
}

// Construct regular expression (ab)*ac
RegexNode *construct_regex1() {
  // create the result
  GroupNode *regex = new GroupNode();

  // create ab node
  GroupNode *ab = new GroupNode();
  ab->add_node(new CharacterNode('a'));
  ab->add_node(new CharacterNode('b'));

  // create the star quantifier
  ZeroNode *star = new ZeroNode(ab);
  regex->add_node(star);

  // set up the main expression
  regex->add_node(new CharacterNode('a'));
  regex->add_node(new CharacterNode('c'));

  return regex;
}

// Construct regular expression (ab)+ac
RegexNode *construct_regex2() {
  // create the result
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE

  return regex;
}

// Construct regular expression (a|(aa))b
RegexNode *construct_regex3() {
  // create the result
  GroupNode *regex = new GroupNode();

  // Vikas Gajjela;Spandana Masadi;Naga Venkata Naresh kollu; Jeesha
  // Lunavath;Navya Leburi

  // YOUR CODE HERE
  OrNode *alt = new OrNode();
  alt->add_node(new CharacterNode('a'));

  GroupNode *aa = new GroupNode();
  aa->add_node(new CharacterNode('a'));
  aa->add_node(new CharacterNode('a'));
  alt->add_node(aa);

  regex->add_node(alt);
  regex->add_node(new CharacterNode('b'));

  return regex;
}

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex4() {
  GroupNode *regex = new GroupNode();
  // Meghana Katne; Lakshman Kakarla; Sravya Akavaram; Lu Zhang;
  // YOUR CODE HERE
  GroupNode *digits = new GroupNode();
  digits->add_node(new RangeNode('0', '9')); // Matches a digit
  OneNode *one_or_more_digits =
      new OneNode(digits); // Matches one or more digits

  // create nodes for (\.[0-9]+)?
  GroupNode *decimal_part = new GroupNode();
  decimal_part->add_node(new CharacterNode('.'));
  GroupNode *decimal_digits = new GroupNode();
  decimal_digits->add_node(new RangeNode('0', '9'));
  OneNode *one_or_more_decimal_digits = new OneNode(decimal_digits);
  OptionalNode *optional_decimal_part = new OptionalNode(decimal_part);

  regex->add_node(one_or_more_digits);
  regex->add_node(optional_decimal_part);

  return regex;
}

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex5() {
  // Sri Priyanka Madamanchi <smadamanchi2s@semo.edu>
  // Bhuvaneswari Thottempudi <bthottempudi2s@semo.edu>
  // Vamsi Kandula <vkandula1s@semo.edu>
  // Joharika Jillelamudi <jjillelamudi1s@semo.edu>
  // Venkatesh Marnedi < vmarnedi1s@semo.edu>
  // Baby Sowmya Sunkara <bsunkara1s@semo.edu>
  // Gopi Krishna Pavuluri <gpavuluri1s@semo.edu>

  GroupNode *regex = new GroupNode();

  // Create an OrNode to match either lowercase or uppercase letters
  OrNode *letter_or = new OrNode();
  letter_or->add_node(new RangeNode('a', 'z'));
  letter_or->add_node(new RangeNode('A', 'Z'));

  // Add the OrNode to match one or more occurrences of letters
  regex->add_node(new OneNode(letter_or));

  return regex;
}

// Construct the regular expression "[^"]*"
RegexNode *construct_regex6() {
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE

  return regex;
}
