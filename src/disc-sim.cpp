#include "disc.h"
//  using Disc and IntPair

#include "display.h"
//  using Display
    using std::vector;
    using std::shared_ptr;
    using std::make_shared;

int main() {
  Display display;

  vector<shared_ptr<Disc>> discs;

  discs.push_back(make_shared<Disc>(
    display.screen_height / 20,
    IntPair(),
    IntPair(2, 2)
  )); // Disc(radius, center, zero-initialized velocity)

  display.setDiscs(discs);
  display.animate();
}
