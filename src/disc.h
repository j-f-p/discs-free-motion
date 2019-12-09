#ifndef DISC_H
#define DISC_H

#include "intPair.h"
// using IntPair

// Disc represents a solid circular object. Its position attribute refers to
// the circle's center.
class Disc {
    const unsigned int radius;

  public:
    IntPair position;
    const IntPair velocity;

    Disc(unsigned int rad, IntPair vel): radius(rad), velocity(vel) { }

    const unsigned int retRadius() { return radius; }

    void move();
};

#endif
