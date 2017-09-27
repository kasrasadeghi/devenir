//
// Created by kasra on 7/25/17.
//

#include <sstream>
#include "Parse.h"
using namespace Parse;

Node Parse::parse(std::vector<Lexer::Token>& ts){
  return Parser(ts).parse();
}

Node Parser::parse() {
  Node program("exec");
  while (!_empty())
    program += _expression();
  return program;
}

Node Parser::_expression() {
  switch(_peek()._type) {
  case Lexer::Type::ID:
    exit(111);
  case Lexer::Type::SYM: {
    _check("+");
    _pop();

    Node plus("+");
    plus += _expression();
    plus += _expression();
    return plus;
  }
  case Lexer::Type::LIT: {
    return _literal();
  }
  }
}

Node Parser::_literal() {
  _check(Lexer::Type::LIT);
  Lexer::Token value = _pop();

  // TODO maybe parse exception or something
  std::stringstream int_stream(value._value);
  int int_value;
  int_stream >> int_value;

  return Node(int_value);
}
