#ifndef MODEL_H
#define MODEL_H

#include "display.h"
// using Display
// using vector
// using unique_ptr
// using shared_ptr

#include "disc.h"
// using Disc

#include <mutex>
// using mutex

namespace model {
  extern std::mutex xclusion;
  extern std::shared_ptr<bool> advance, move_disc;
  extern Display display;
  void addDisc(std::unique_ptr<Disc>);
  const std::vector<std::unique_ptr<Disc>>& retDiscs();
  void kinematics();
}

#endif
