#include <iostream>
#include <vector>
#include "Lexer.h"

using std::string;
using std::vector;
using std::size_t;

string read_input() {
  return "+ 1 2";
}

int main() {
  string input = read_input();
  vector<Token> tokens = tokenize(input);
  return 0;
}