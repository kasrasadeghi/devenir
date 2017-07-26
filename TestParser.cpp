#include <gtest/gtest.h>

using std::string;

using std::vector;

using std::cout;
using std::endl;


#include "Parser.h"

using namespace Parse;
using namespace Lexer;

/**
 * All parser tests depend on a working Lexer.
 */

TEST(Parser, node_ctor) {
  Node node("what");
  ASSERT_EQ(node.s(), "what");
}

TEST(Parser, node_int_ctor) {
  Node node(10);
  ASSERT_EQ(node.i(), 10);
}

TEST(Parser, tree) {
  string input = "+ 1 2 ";
  vector<Token> tokens = tokenize(input);
  ASSERT_EQ(tokens[1]._value, "1");
  ASSERT_EQ(tokens[2]._value, "2");
  Parser p(tokens);
  const Node tree = p.parse();
  ASSERT_EQ(tree.s(), "exec");
  ASSERT_EQ(tree[0].s(), "+");
  EXPECT_EQ(tree[0][0].i(), 1);
  EXPECT_EQ(tree[0][1].i(), 2);
}
