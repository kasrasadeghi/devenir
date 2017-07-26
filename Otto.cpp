#include "Otto.h"
#include "Parse.h"
#include <iostream>

using namespace VM;

void dump(const Parse::Node& root, int level=0) {
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

int Otto::evaluate(const Parse::Node& tree) {
  assert(tree.s() == "exec");
  dump(tree);
  return 0;
}
