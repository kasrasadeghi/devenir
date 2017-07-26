#ifndef DEVENIR_PARSER_H
#define DEVENIR_PARSER_H


#include <vector>
#include <string>
#include <utility>
#include <assert.h>
#include <variant>
#include <iostream>
#include "Lexer.h"

namespace Parse {
  enum class Type {

  };

  /**
   * very primitive multitree node class
   */
  class Node {
  public:
    Node(const std::string& value): _children(), _value(value) {}
    Node(int value):                _children(), _value(value) {}
    Node& operator+=(Node child)   { _children.push_back(child); return *this; }
    Node& operator[](size_t index) { return _children[index];              }
    const Node& operator[](size_t i) const
                                   { return _children[i]; }

    std::string s() const          { return std::get<std::string>(_value); }
    int         i() const          { return std::get<int>        (_value); } // TODO node move?

    std::vector<Node>::const_iterator begin() const
                                   { return _children.begin(); }
    std::vector<Node>::iterator begin()
                                   { return _children.begin(); }
    std::vector<Node>::const_iterator cbegin()
                                   { return _children.cbegin(); }
    std::vector<Node>::const_iterator end() const
                                   { return _children.end(); }
    std::vector<Node>::iterator end()
                                   { return _children.end(); }
    std::vector<Node>::const_iterator cend()
                                   { return _children.cend(); }

    inline friend std::ostream& operator<<(std::ostream& out, Node n) {
      std::visit([&out](auto arg){out << arg;}, n._value);
      return out;
    }
  private:
    std::vector<Node> _children;
    std::variant<int, std::string> _value;
  };

  class Parser {
  public:
    Parser(std::vector<Lexer::Token>& ts): _vec(ts) {}
    Node parse();

  private:
    const std::vector<Lexer::Token>& _vec;
    size_t _index = 0;

    Lexer::Token _pop()            { return _vec[_index++];         }
    Lexer::Token _curr()           { return _vec[_index];           }
    void _check(std::string val)   { assert(_curr()._value == val); }
    void _check(Lexer::Type type)  { assert(_curr()._type == type); }

    Node _expression();
    Node _literal();

    bool _empty() { return _index == _vec.size(); }
  };

  Node parse(std::vector<Lexer::Token>& ts);
}


#endif //DEVENIR_PARSER_H
