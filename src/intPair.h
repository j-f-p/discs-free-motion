#ifndef INTPAIR_H
#define INTPAIR_H

struct IntPair {
  short int x, y;
  // IntPair(): x(0), y(0) { }
  IntPair(short X = 0, short Y = 0): x(X), y(Y) { }
};

#endif
