#ifndef MODEL_H
#define MODEL_H

#include "disc.h"
// using Disc

#include <memory>
// using unique_ptr

#include <mutex>
// using mutex

#include <vector>
// using vector

namespace model {
  extern std::mutex xclusion;
  extern bool advance, move_disc;
  void addDisc(std::unique_ptr<Disc>);
  const std::vector<std::unique_ptr<Disc>>& retDiscs();
  void kinematics();
}

#endif
