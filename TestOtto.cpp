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