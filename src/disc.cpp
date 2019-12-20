#include "disc.h"
//  implementing Disc::move for disc.h

#include <cmath>
    using std::fmod;

// Move Disc instance by updating its position based on rectilinear motion with
// constant velocity and periodic boundaries. The change in time to compute the
// change in position is approximately 1 frame life so that the velocity is
// approximately in units of pixel lengths per frame life (pixels/frame).
void Disc::move(short screen_length) {
  circle.center.x += velocity.x;
  circle.center.y += velocity.y;

  // Apply periodic boundary conditions.
  if (circle.center.x < 0  or  circle.center.x > screen_length)
    circle.center.x = fmod(circle.center.x + screen_length, screen_length);

  if (circle.center.y < 0  or  circle.center.y > screen_length)
    circle.center.y = fmod(circle.center.y + screen_length, screen_length);
}
