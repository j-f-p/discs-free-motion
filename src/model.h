#ifndef MODEL_H
#define MODEL_H

#include "disc.h"
// using Disc

#include <vector>
// using vector

#include <memory>
// using unique_ptr

namespace model {
  void addDisc(std::unique_ptr<Disc>);
  const std::vector<std::unique_ptr<Disc>>& retDiscs();
}

#endif
