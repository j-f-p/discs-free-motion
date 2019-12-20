#ifndef MODEL_H
#define MODEL_H

#include "display.h"
// using Display
// using vector
// using unique_ptr
// using shared_ptr

#include "disc.h"
// using Disc

namespace model {
  extern Display display;
  void addDisc(std::unique_ptr<Disc>);
  const std::vector<std::unique_ptr<Disc>>& retDiscs();
  void kinematics(std::shared_ptr<bool>, std::shared_ptr<bool>);
}

#endif
