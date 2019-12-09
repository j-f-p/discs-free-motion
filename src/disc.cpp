#include "disc.h"
// implementing Disc::move for disc.h
// using IntPair

// Move Disc instance by updating its position based on rectilinear motion with
// constant velocity.
void Disc::move() {
  // TODO: employ non-unit time delta
  position.x += velocity.x;
  position.y += velocity.y;
}
