#include "disc.h"
//  using Disc and IntPair

#include "display.h"
//  using Display
    using std::vector;
    using std::unique_ptr;
    using std::make_unique;

#include <random>
    using std::mt19937;
    using std::random_device;
    using std::uniform_int_distribution;

#include <utility>
    using std::move;

int main() {
  Display display;

  // Generate random positions and velocities based on prescribed ranges.
  random_device rd; // non-deterministic seed generator
  mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
  uniform_int_distribution<short> pos_dis(0, display.screen_height);
  uniform_int_distribution<short> vel_dis(-4, -4); // pixels / frame

  display.addDisc(move(make_unique<Disc>(
    display.screen_height / 20,
    IntPair( pos_dis(gen), pos_dis(gen) ),
    IntPair( vel_dis(gen), vel_dis(gen) )
  ))); // Disc(radius, center, zero-initialized velocity)

  unique_ptr<bool> advance(new bool{true});
  display.animate(move(advance));
}
