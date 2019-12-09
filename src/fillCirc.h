#ifndef FILLCIRC_H
#define FILLCIRC_H

#include "SDL.h"
// using SDL_Renderer

#include "intPair.h"
// using IntPair

struct Circ {
  IntPair center;
  const unsigned int radius;
};

void RenderFillCirc(SDL_Renderer*, Circ*);

#endif
