#include "fillCirc.h"

// Comparison between signed int i and unsigned int j: i <= j.
bool leq(int i, unsigned int u) {
  return  i < 0  ||  static_cast<unsigned int>(i) <= u;
}

void RenderFillCirc(SDL_Renderer* renderer, Circ* circ) {
  const unsigned int rad = circ->radius;
  int px, py;
  for( px = -rad;  leq(px, rad);  ++px )
  for( py = -rad;  leq(py, rad);  ++py )
    if( leq(px*px + py*py,  rad*rad) )
      SDL_RenderDrawPoint(renderer, circ->x_center + px, circ->y_center + py);
}
