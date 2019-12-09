#ifndef DISPLAY_H
#define DISPLAY_H

#include "disc.h"
// using Disc

#include <vector>
// using vector

#include <memory>
// using shared_ptr

// Display is a manager of the logic that displays the disk simulation.
class Display {
    const std::vector<std::shared_ptr<Disc>> discs;

  public:
    Display(std::vector<std::shared_ptr<Disc>>& initDiscs)
      : discs(initDiscs) { }

    void animate() const;
};

#endif
