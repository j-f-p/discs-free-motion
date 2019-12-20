#include "renderFillCirc.h"
// implementing RenderFillCirc for renderFillCirc.h
// using Circ, SDL_Renderer and SDL_RenderDrawPoint

void RenderFillCirc(SDL_Renderer* renderer, const Circ* circ) {
  const short rad = circ->radius;
  short px, py; // pixel coordinates relative to circle center
  for( px = -rad;  px<=rad;  ++px )
  for( py = -rad;  py<=rad;  ++py )
    if( px*px + py*py <= rad*rad )
      SDL_RenderDrawPoint(renderer, circ->center.x + px, circ->center.y + py);

}
