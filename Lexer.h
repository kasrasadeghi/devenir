#ifndef GRAPH_LEXER_H
#define GRAPH_LEXER_H

#include <string>
#include <vector>
#include <iostream>

namespace Lexer {
  enum class Type {
    ID,  // identifier
    SYM, // symbol
    LIT  // literal
  };

  inline std::ostream& operator<<(std::ostream & out, Lexer::Type & t) {
    switch(t) {
    case Type::ID:
      out << "ID";
      return out;
    case Type::SYM:
      out << "SYM";
      return out;
    case Type::LIT:
      out << "LIT";
      return out;
    }
  }

  struct Token {
    Token(Type type, std::string value): _type(type), _value(value) {}
    Type _type;
    std::string _value;
    friend bool operator==(const Token& A, const Token& B) {
      return A._type == B._type && A._value == B._value;
    }
  };

  std::vector<Token> tokenize(std::string input);
}

#endif //GRAPH_LEXER_H
