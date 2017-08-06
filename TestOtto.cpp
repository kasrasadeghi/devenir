#include <gtest/gtest.h>
#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Parse.h"

#include "Otto.h"
#include "Lexer.h"
using Lexer::Token;
using Lexer::tokenize;

TEST(Otto, dump) {
  string input = "+ 1 2 ";
  vector<Token> tokens = tokenize(input);
  const Parse::Node tree = Parse::parse(tokens);
  VM::Otto otto;
  otto.dump(tree);
}

TEST(Otto, evaluate) {
  string input = "+ 1 2 ";
  vector<Token> tokens = tokenize(input);
  const Parse::Node tree = Parse::parse(tokens);
  VM::Otto otto;
  otto.evaluate(tree);
  ASSERT_EQ(otto.peek(), 3);
}

TEST(Otto, evaluate_bigger) {
  string input = "+ 1 140 ";
  vector<Token> tokens = tokenize(input);
  const Parse::Node tree = Parse::parse(tokens);
  VM::Otto otto;
  otto.evaluate(tree);
  ASSERT_EQ(otto.peek(), 141);
}

TEST(Otto, evaluate_reverse_polish) {
  string input = "+ 1 + 1 3";
  vector<Token> tokens = tokenize(input);
  const Parse::Node tree = Parse::parse(tokens);
  VM::Otto otto;

  try {
    otto.evaluate(tree);
  } catch(...) {
    std::cout << "reverse polish not implemented yet" << std::endl;
    ASSERT_TRUE(false);
  }
  ASSERT_EQ(otto.peek(), 5);
}