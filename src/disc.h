#ifndef DISC_H
#define DISC_H

#include "intPair.h"
// using IntPair

// Disc represents a solid circular object. Its position attribute refers to
// the circle's center.
class Disc {
    const unsigned short radius;

  public:
    IntPair position;
    const IntPair velocity;

    Disc(unsigned short rad, IntPair pos, IntPair vel)
      : radius(rad), position(pos), velocity(vel) { }

    const unsigned short retRadius() { return radius; }
    void setPosition(IntPair &pos) { position = pos; }

    void move();
};

#endif
