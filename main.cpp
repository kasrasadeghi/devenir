#include <iostream>
#include <vector>
#include "Lexer.h"
#include "Parser.h"

using std::string;
using std::vector;
using std::size_t;

string read_input() {
  return "+ 1 2";
}

int main() {
  string input = read_input();
  vector<Lexer::Token> tokens = Lexer::tokenize(input);
  Parse::Node parse_tree = Parse::parse(tokens);
}