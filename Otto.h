/**
 * Otto is the Virtual Machine implementation for Devenir.
 */

#ifndef DEVENIR_OTTO_H
#define DEVENIR_OTTO_H

#include <stack>
#include "Parse.h"

namespace VM {
  class Otto {
  private:
    std::stack<long> _stack;
    void _push(long val) { _stack.push(val); }
    long _pop()          { long temp = _stack.top(); _stack.pop(); return temp; }

    void _expression(const Parse::Node& Node);
    void _literal(const Parse::Node& Node);

  public:
    long peek() { return _stack.top(); }
    int evaluate(const Parse::Node& tree);
    void dump(const Parse::Node& tree, int level = 0);
  };

}

#endif //DEVENIR_OTTO_H
