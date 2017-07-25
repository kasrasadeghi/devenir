#ifndef DEVENIR_PARSER_H
#define DEVENIR_PARSER_H


#include <vector>
#include <string>
#include "Lexer.h"

namespace Parser {
  enum class Type {

  };

  /**
   * very primitive tree node class
   */
  class Node {
  public:
    Node(std::string value): _children(), _value(value) {}
    void add(Node&& child) { _children.push_back(std::move(child)); }
    std::string dump() { return _value; }
  private:
    std::vector<Node> _children;
    std::string _value;
  };

  Node parse(std::vector<Lexer::Token>);
}


#endif //DEVENIR_PARSER_H
