#include "disc.h"
// implementing Disc::move for disc.h
// using IntPair

#include <cmath>
    using std::fmod;

// Move Disc instance by updating its position based on rectilinear motion with
// constant velocity.
void Disc::move(short screen_length) {
  // TODO: employ non-unit time delta
  position.x += velocity.x;
  position.y += velocity.y;

  if (position.x < 0  or  position.x > screen_length)
    position.x = fmod(position.x + screen_length, screen_length);

  if (position.y < 0  or  position.y > screen_length)
    position.y = fmod(position.y + screen_length, screen_length);
}
