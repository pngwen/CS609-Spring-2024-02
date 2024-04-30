// File: regex_lexer.cpp
// Purpose: A lexer for the regular expression language
// Author: Robert Lowe
#include "regex_lexer.h"
#include "regex.h"
#include <iostream>
#include <string>

// The tokens
enum Token {
  CHAR_TOK = 1,
  CLASS_TOK,
  INV_CLASS_TOK,
  LPAREN_TOK,
  RPAREN_TOK,
  PIPE_TOK,
  WILDCARD_TOK,
  QUANT_TOK,
  RANGE_TOK
};

//////////////////////////////////////////
// Static Helper Functions
//////////////////////////////////////////

// Construct a handler for escaped characters "\\."
static RegexNode *construct_escaped_node() {
  GroupNode *result = new GroupNode();
  result->add_node(new CharacterNode('\\'));
  result->add_node(new WildcardNode());
  return result;
}

// Character Token: [^.()\[\]*+?|]|(\\n | \\t | \\.)
static RegexNode *construct_char_node() {
  OrNode *result = new OrNode();

  // Construct the inverse character class
  OrNode *inv_spec = new OrNode();
  inv_spec->add_node(new CharacterNode('.'));
  inv_spec->add_node(new CharacterNode('('));
  inv_spec->add_node(new CharacterNode(')'));
  inv_spec->add_node(new CharacterNode('['));
  inv_spec->add_node(new CharacterNode(']'));
  inv_spec->add_node(new CharacterNode('*'));
  inv_spec->add_node(new CharacterNode('+'));
  inv_spec->add_node(new CharacterNode('?'));
  inv_spec->add_node(new CharacterNode('|'));
  result->add_node(new InverseNode(inv_spec));

  // Build the escape sequences
  result->add_node(construct_escaped_node());

  return result;
}

// Construct class spec: ([^\]] | \\.)+
static RegexNode *construct_class_spec_node() {
  OrNode *spec_or = new OrNode();
  spec_or->add_node(new InverseNode(new CharacterNode(']')));
  spec_or->add_node(construct_escaped_node());
  return new OneNode(spec_or);
}

// Class Token \[([^\]]|(\\])|(\\n)|(\\t)|(\\.)|(.-.))+\]
static RegexNode *construct_class_node() {
  GroupNode *result = new GroupNode();

  result->add_node(new CharacterNode('['));
  result->add_node(construct_class_spec_node());
  result->add_node(new CharacterNode(']'));

  return result;
}

static RegexNode *construct_inv_class_node() {
  GroupNode *result = new GroupNode();

  result->add_node(new CharacterNode('['));
  result->add_node(new CharacterNode('^'));
  result->add_node(construct_class_spec_node());
  result->add_node(new CharacterNode(']'));

  return result;
}

// Lparen: \(
static RegexNode *construct_lparen_node() { return new CharacterNode('('); }

// Rparen: \)
static RegexNode *construct_rparen_node() { return new CharacterNode(')'); }

// Pipe: \|
static RegexNode *construct_pipe_node() { return new CharacterNode('|'); }

// Wildcard: \.
static RegexNode *construct_wildcard_node() { return new CharacterNode('.'); }

// Quantifier: \* | \+ | \?
static RegexNode *construct_quantifier_node() {
  OrNode *result = new OrNode();
  result->add_node(new CharacterNode('*'));
  result->add_node(new CharacterNode('+'));
  result->add_node(new CharacterNode('?'));
  return result;
}

// Range: .-.
static RegexNode *construct_range_node() {
  GroupNode *result = new GroupNode();
  result->add_node(new WildcardNode());
  result->add_node(new CharacterNode('-'));
  result->add_node(new WildcardNode());
  return result;
}

// Translate a character
static char translate_char(const std::string &str) {
  // handle the simple characters
  if (str.length() == 1) {
    return str[0];
  } else if (str[1] == 'n') {
    // newline!
    return '\n';
  } else if (str[1] == 't') {
    // tab!
    return '\t';
  } else {
    // literal escaped character
    return str[1];
  }
}

// Handle the construction of the regex node
// for a character match.
static void handle_character(RegexLexer::LexerToken &result) {
  result.tok = RegexLexer::REGEX_NODE;
  result.node = new CharacterNode(translate_char(result.lexeme));
}

// Handle the class spec
static RegexNode *handle_class_spec(const std::string &spec, Lexer &lexer) {
  OrNode *result = new OrNode();
  Lexer::Token t;

  lexer.input(spec);

  while ((t = lexer.next()).tok != RegexLexer::END_OF_INPUT) {
    if (t.tok == CHAR_TOK) {
      result->add_node(new CharacterNode(translate_char(t.lexeme)));
    } else if (t.tok == RANGE_TOK) {
      result->add_node(new RangeNode(t.lexeme[0], t.lexeme[2]));
    }
  }

  return result;
}

static void handle_class(RegexLexer::LexerToken &result, Lexer &lexer) {
  std::string spec = result.lexeme.substr(1, result.lexeme.length() - 2);
  result.tok = RegexLexer::REGEX_NODE;
  result.node = handle_class_spec(spec, lexer);
}

static void handle_inv_class(RegexLexer::LexerToken &result, Lexer &lexer) {
  // TODO: Implement this method
}

static void handle_quantifier(RegexLexer::LexerToken &result) {
  switch (result.lexeme[0]) {
  case '*':
    result.tok = RegexLexer::ZERO_QUANT;
    break;
  case '+':
    result.tok = RegexLexer::ONE_QUANT;
    break;
  case '?':
    result.tok = RegexLexer::OPTION_QUANT;
    break;
  }
}

//////////////////////////////////////////
// RegexLexer Methods
//////////////////////////////////////////

// construct a regular expression lexer
RegexLexer::RegexLexer() {
  // blank input
  input("");

  // build the main lexer
  _lexer.add_token(CHAR_TOK, construct_char_node());
  _lexer.add_token(INV_CLASS_TOK, construct_inv_class_node());
  _lexer.add_token(CLASS_TOK, construct_class_node());
  _lexer.add_token(LPAREN_TOK, construct_lparen_node());
  _lexer.add_token(RPAREN_TOK, construct_rparen_node());
  _lexer.add_token(PIPE_TOK, construct_pipe_node());
  _lexer.add_token(WILDCARD_TOK, construct_wildcard_node());
  _lexer.add_token(QUANT_TOK, construct_quantifier_node());

  // build the spec lexer
  _spec_lexer.add_token(CHAR_TOK, construct_char_node());
  _spec_lexer.add_token(RANGE_TOK, construct_range_node());
}

// set the input string
void RegexLexer::input(const std::string &_input) { _lexer.input(_input); }

// get the input string
std::string RegexLexer::input() const { return _lexer.input(); }

// get the current position
size_t RegexLexer::position() const { return _lexer.position(); }

// check to see if we are at the end of the input
bool RegexLexer::at_end() const { return _lexer.at_end(); }

// get the next RegexNode, null if there is none
RegexLexer::LexerToken RegexLexer::next() {
  // get the textual node and then do our own translation
  Lexer::Token lt = _lexer.next();
  LexerToken result;

  // copy the basic fields
  result.lexeme = lt.lexeme;
  result.pos = lt.pos;

  // assume we are building a regex expression
  result.tok = REGEX_NODE;

  // handle the token
  switch (lt.tok) {
  case CHAR_TOK:
    handle_character(result);
    break;
  case CLASS_TOK:
    handle_class(result, _spec_lexer);
    break;
  case INV_CLASS_TOK:
    handle_inv_class(result, _spec_lexer);
    break;
  case LPAREN_TOK:
    result.tok = LPAREN;
    break;
  case RPAREN_TOK:
    result.tok = RPAREN;
    break;
  case PIPE_TOK:
    result.tok = OR;
    break;
  case WILDCARD_TOK:
    result.node = new WildcardNode();
    break;
  case QUANT_TOK:
    handle_quantifier(result);
    break;
  case Lexer::INVALID:
    result.tok = INVALID;
    break;
  case Lexer::END_OF_INPUT:
    result.tok = END_OF_INPUT;
    break;
  }

  return result;
}