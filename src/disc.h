#ifndef DISC_H
#define DISC_H

#include "intPair.h"
// using IntPair

// Disc represents a solid circular object. Its position attribute refers to
// the circle's center. Having only public members, it is defined as a struct.
struct Disc {
    const unsigned short radius;

    IntPair position;
    const IntPair velocity;

    Disc(unsigned short rad, IntPair pos, IntPair vel)
      : radius(rad), position(pos), velocity(vel) { }

    void move();
};

#endif
