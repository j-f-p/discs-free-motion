#ifndef FILLCIRC_H
#define FILLCIRC_H

#include "intPair.h"
// using IntPair

#include "SDL.h"
// using SDL_Renderer

struct Circ {
  IntPair center;
  const unsigned short radius;
};

void RenderFillCirc(SDL_Renderer*, Circ*);

#endif
