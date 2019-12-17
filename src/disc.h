#ifndef DISC_H
#define DISC_H

#include "circ.h"
// using Circ
// using IntPair

// Disc represents a solid circular object. Because it has only public members
// and I favor the efficiency of direct data access for this project, it is
// defined as a struct.
struct Disc {
    Circ circle;
    const IntPair velocity;
    Disc(Circ circ, IntPair vel): circle(circ), velocity(vel) { }
    void move(short);
};

#endif
