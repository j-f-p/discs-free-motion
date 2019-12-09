#include "fillCirc.h"
// using Circ from fillCirc.h
// implementing RenderFillCirc for fillCirc.h

// fillCirc.h includes intPair.h and SDL.h
// using IntPair from intPair.h
// using SDL_Renderer and SDL_RenderDrawPoint from SDL.h

void RenderFillCirc(SDL_Renderer* renderer, Circ* circ) {
  // Comparison between signed int i and unsigned int u: i <= u.
  auto leq = [](int i, unsigned int u)->bool {
    return  i < 0  ||  static_cast<unsigned int>(i) <= u;
  };

  const unsigned int rad = circ->radius;
  int px, py; // pixel coordinates relative to circle center
  for( px = -rad;  leq(px, rad);  ++px )
  for( py = -rad;  leq(py, rad);  ++py )
    if( leq(px*px + py*py,  rad*rad) )
      SDL_RenderDrawPoint(renderer, circ->center.x + px, circ->center.y + py);

}
