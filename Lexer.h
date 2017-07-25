#ifndef GRAPH_LEXER_H
#define GRAPH_LEXER_H

#include <string>
#include <vector>

namespace Lexer {
  enum class Type {
    ID,  // identifier
    SYM, // symbol
    LIT  // literal
  };

  struct Token {
    Token(Type type, std::string value): _type(type), _value(value) {}
    Token(std::string value): _type(Type::ID), _value(value) {}

    Type _type;
    std::string _value;
  };

  std::vector<Token> tokenize(std::string input);
}

#endif //GRAPH_LEXER_H
