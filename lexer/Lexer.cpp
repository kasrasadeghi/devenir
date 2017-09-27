#include "Lexer.h"

using std::vector;
using std::string;

using namespace Lexer;

inline bool numeric(char c) {
   return c - '0' >= 0 && c - '0' < 10;
}

vector<Token> Lexer::tokenize(string input) {
  vector<Token> result;
  string acc = "";
  for (size_t i = 0, len = input.size(); i < len; ++i) {
    char c = input[i];
    switch(c) {
    case ' ':
      if (acc != "") {
        result.push_back({Type::LIT, acc});
        acc = "";
      }
      break;
    case '+':
      result.push_back({Type::SYM, "+"});
      break;
    default:
      if (numeric(c)) {
        acc += c;
      }
    }
  }
  if (acc != "") {
    result.push_back({Type::LIT, acc});
  }
  return result;
}