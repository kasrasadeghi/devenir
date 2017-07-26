/**
 * Otto is the Virtual Machine implementation for Devenir.
 */

#ifndef DEVENIR_OTTO_H
#define DEVENIR_OTTO_H

#include "Parse.h"

namespace VM {
  class Otto {
  private:

  public:
    int evaluate(const Parse::Node& tree);
  };

}

#endif //DEVENIR_OTTO_H