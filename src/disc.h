#ifndef DISC_H
#define DISC_H

#include "intPair.h"
// using IntPair

// Disc represents a solid circular object. Its position attribute refers to
// the circle's center.
class Disc {
    const unsigned int radius;

  public:
    IntPair position, velocity;

    Disc(unsigned int rad): radius(rad) { }

    const unsigned int retRadius() { return radius; }

    void move() const;
}

#endif
