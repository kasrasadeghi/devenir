#include <gtest/gtest.h>
#include "Lexer.h"

#include <string>
#include <vector>

using std::string;
using std::vector;

TEST(Lexer, tokenize) {
  string input = "+ 1 2 ";
  vector<Token> tokens = tokenize(input);

  ASSERT_EQ(tokens.size(), 3);
  ASSERT_EQ(tokens[0]._value, "+");
  ASSERT_EQ(tokens[1]._value, "1");
  ASSERT_EQ(tokens[2]._value, "2");
}

TEST(Lexer, tokenize_without_whitespace) {
  string input = "+ 1 2";
  vector<Token> tokens = tokenize(input);

  ASSERT_EQ(tokens.size(), 3);
  ASSERT_EQ(tokens[0]._value, "+");
  ASSERT_EQ(tokens[1]._value, "1");
  ASSERT_EQ(tokens[2]._value, "2");
}