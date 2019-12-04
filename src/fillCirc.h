#include "SDL.h"

struct Circ {
  int x_center;
  int y_center;
  unsigned int radius;
};

void RenderFillCirc(SDL_Renderer*, Circ*);
