#include "Otto.h"
#include "../parser/Parse.h"
#include <iostream>

using namespace VM;

void Otto::dump(const Parse::Node& root, int level) {
  for (int i = 0; i < level; ++i) std::cout << "  ";

  std::cout << root << std::endl;
  ++level;
  for (const Parse::Node& child : root) {
    try {
      dump(child, level);
    } catch(...) {
      std::cout << "sad" << std::endl;
    }
  }
}

long Otto::evaluate(const Parse::Node& tree) {
  assert(tree.s() == "exec");
  _expression(tree[0]);
  return _pop();
}

void Otto::_expression(const Parse::Node& node) {
  assert(node.s() == "+");
  _literal(node[0]);
  _literal(node[1]);
  _push(_pop() + _pop());
}

void Otto::_literal(const Parse::Node& node) {
  _push(node.i());
}
