#include "Lexer.h"

using std::vector;
using std::string;

using namespace Lexer;

vector<Token> Lexer::tokenize(string input) {
  vector<Token> result;
  string acc = "";
  for (size_t i = 0, len = input.size(); i < len; ++i) {
    char c = input[i];
    switch(c) {
    case ' ':
      if (acc != "") {
        result.push_back({acc});
        acc = "";
      }
      break;
    case '+':
      result.push_back({Type::SYM, "+"});
      break;
    default:
      int offset = c - '0';
      if (offset >= 0 && offset < 10) {
        acc += c;
      }
    }
  }
  if (acc != "") {
    result.push_back({acc});
  }
  return result;
}