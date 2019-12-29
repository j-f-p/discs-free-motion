#include "model.h"
//  using Display, Disc, Circ and IntPair
//  using model::display
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
  uniform_int_distribution<short> pos_dis(0, model::display.screen_height);
  uniform_int_distribution<short> vel_dis(-4, 4); // ~= pixels / frame

  model::addDisc(move(make_unique<Disc>(
    Circ( IntPair( pos_dis(gen), pos_dis(gen) ),
          model::display.screen_height / 20      ),
    IntPair( vel_dis(gen), vel_dis(gen) )
  ))); // Disc(radius, center, zero-initialized velocity)

  thread sim_thread(model::kinematics);
  model::display.animate();
  sim_thread.join();
}
