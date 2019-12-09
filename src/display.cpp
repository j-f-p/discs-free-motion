#include "display.h"
// implementing Display::animate for display.h

// display.h includes disc.h
// using Disc from Disc.h

// disc.h includes intPair.h
// using IntPair from intPair.h

// display.h includes fillCirc.h
// using Circ and RenderFillCirc from fillCirc.h

// fillCirc.h includes intPair.h and SDL.h, though intPair.h is not re-included
// using functions and constants that begin with "SDL_" from SDL.h

// display.h includes <vector>
using std::vector;

// display.h includes <memory>
using std::shared_ptr;

// Animate displays an animation of the simulation.
void Display::animate() const { }
