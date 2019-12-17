#ifndef CIRC_H
#define CIRC_H

#include "intPair.h"
// using IntPair

struct Circ {
  IntPair center;
  const unsigned short radius;
  Circ(IntPair ctr, unsigned short rad): center(ctr), radius(rad) { }
};

#endif
