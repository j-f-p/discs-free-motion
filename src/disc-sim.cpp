#include "display.h"
//  using display::screen_width and display::screen_height
//  using display::animate

#include "model.h"
//  using Disc, Circ and IntPair
//  using model::addDisc
//  using model::kinematics
    using std::make_unique;

#include <random>
    using std::mt19937;
    using std::random_device;
    using std::uniform_int_distribution;

#include <thread>
    using std::thread;

#include <utility>
    using std::move;

int main() {
  // Generate random positions and velocities based on prescribed ranges.
  random_device rd; // non-deterministic seed generator
  mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator
  uniform_int_distribution<short> x_pos_dis(0, display::screen_width);
  uniform_int_distribution<short> y_pos_dis(0, display::screen_height);
  uniform_int_distribution<short> vel_dis(-4, 4); // ~= pixels / frame

  for( short disc_i=0;  disc_i < model::n_discs;  ++disc_i )
    model::addDisc(move(make_unique<Disc>(
      Circ( IntPair( x_pos_dis(gen), y_pos_dis(gen) ),
            display::screen_height / 20      ),
      IntPair( vel_dis(gen), vel_dis(gen) )
    ))); // Disc(radius, center, zero-initialized velocity)

  thread calc_thread(model::kinematics);
  display::animate();
  calc_thread.join();
}
