#ifndef CIRC_H
#define CIRC_H

#include "intPair.h"
// using IntPair

struct Circ {
  IntPair center;
  const short radius;
  Circ(IntPair ctr, short rad): center(ctr), radius(rad) { }
};

#endif
