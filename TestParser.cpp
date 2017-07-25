#include <gtest/gtest.h>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;


#include "Parser.h"

using namespace Parser;
using namespace Lexer;

/**
 * All parser tests depend on a working Lexer.
 */

TEST(Parser, node_ctor) {
  Node node("what");
  ASSERT_EQ(node.dump(), "what");
}

TEST(Parser, parse) {
  string input = "+ 1 2 ";
  vector<Token> tokens = tokenize(input);
}