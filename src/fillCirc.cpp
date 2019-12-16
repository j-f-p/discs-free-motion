#include "fillCirc.h"
// implementing RenderFillCirc for fillCirc.h
// using Circ, IntPair, SDL_Renderer and SDL_RenderDrawPoint

void RenderFillCirc(SDL_Renderer* renderer, const Circ* circ) {
  // Comparison between signed short i and unsigned short u: i <= u.
  auto leq = [](short i, unsigned short u)->bool {
    return  i < 0  ||  static_cast<unsigned short>(i) <= u;
  };

  const unsigned short rad = circ->radius;
  short px, py; // pixel coordinates relative to circle center
  for( px = -rad;  leq(px, rad);  ++px )
  for( py = -rad;  leq(py, rad);  ++py )
    if( leq(px*px + py*py,  rad*rad) )
      SDL_RenderDrawPoint(renderer, circ->center.x + px, circ->center.y + py);

}
