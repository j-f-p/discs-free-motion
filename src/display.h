#ifndef DISPLAY_H
#define DISPLAY_H

#include "disc.h"
// using Disc

// disc.h includes intPair.h
// using IntPair from intPair.h

#include "fillCirc.h"
// using Circ and RenderFillCirc from fillCirc.h

// fillCirc.h includes intPair.h and SDL.h
// using functions and constants that begin with "SDL_" from SDL.h

#include <vector>
#include <memory>

// Display is a manager of the logic that displays the disk simulation.
class Display {
    const std::vector<std::shared_ptr<Disc>> discs;

  public:
    Display(std::vector<std::shared_ptr<Disc>>& initDiscs)
      : discs(initDiscs) { }
      
    void animate() const;
};

#endif
