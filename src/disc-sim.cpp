#include "disc.h"
//  using Disc and IntPair

#include "display.h"
//  using Display
    using std::vector;
    using std::shared_ptr;
    using std::unique_ptr;
    using std::make_shared;

#include <random>
    using std::mt19937;
    using std::random_device;
    using std::uniform_int_distribution;

#include <utility>
    using std::move;

int main() {
  Display display;

  vector<shared_ptr<Disc>> discs;

  // Generate random positions and velocities based on prescribed ranges.
  random_device rd; // non-determistic seed generator
  mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
  uniform_int_distribution<short> pos_dis(0, display.screen_height);
  uniform_int_distribution<short> vel_dis(1, 5); // pixels / frame

  discs.push_back(make_shared<Disc>(
    display.screen_height / 20,
    IntPair( pos_dis(gen), pos_dis(gen) ),
    IntPair( vel_dis(gen), vel_dis(gen) )
  )); // Disc(radius, center, zero-initialized velocity)

  display.setDiscs(discs);

  unique_ptr<bool> advance(new bool{true});
  display.animate(move(advance));
}
