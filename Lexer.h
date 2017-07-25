//
// Created by kasra on 7/24/17.
//

#ifndef GRAPH_LEXER_H
#define GRAPH_LEXER_H

#include <string>
#include <vector>

struct Token {
  Token(std::string value): _value(value) {}
  std::string _value;
};

std::vector<Token> tokenize(std::string input) {
  std::vector<Token> result;
  std::string acc = "";
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
      result.push_back(Token("+"));
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

#endif //GRAPH_LEXER_H
