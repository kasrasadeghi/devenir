//
// Created by kasra on 7/25/17.
//

#include "Parser.h"
using namespace Parser;

Node Parser::parse(std::vector<Lexer::Token> tokens) {
  Node program("exec");
  for (const Lexer::Token& token : tokens) {
    switch(token._type) {
    case Lexer::Type::ID:
      exit(111); //TODO implement ID parsing
      break;
    case Lexer::Type::SYM:
      //TODO fixme
      // for now, this can only be a plus operator '+'
      program.add(Node{"what"});
      break;
    case Lexer::Type::LIT:
      break;
    }
  }
  return program;
}
