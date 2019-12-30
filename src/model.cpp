#include "display.h"
//  using display::idle and display::frame_life

#include "model.h"
//  initilizing xclusion, advance and move_disc for model.h
//  implementing addDisc, retDiscs and kinematics for model.h
//  using Disc
    using std::shared_ptr;
    using std::unique_ptr;
    using std::vector;
    using std::mutex;

#include <chrono>
    using std::chrono::microseconds;
    using std::chrono::milliseconds;

#include <thread>
    using std::this_thread::sleep_for;

#include <utility>
    using std::move;

namespace model {
  namespace {
    vector<unique_ptr<Disc>> discs;
  }

  mutex xclusion;
  shared_ptr<bool> advance(new bool{true}), move_disc(new bool{});

  void addDisc(unique_ptr<Disc> disk) {
    discs.push_back(move(disk));
  }

  const vector<unique_ptr<Disc>>& retDiscs() {
    return discs;
  }

  void kinematics() {
    while (*advance) { // always entered when *move_disc = false
      if (display::idle)
        sleep_for(milliseconds(display::frame_life - 2)); // to moderate CPU
      else // always entered when *move_disc = false
        sleep_for(microseconds(100)); // to less moderate CPU

      if (*move_disc==true) {
        xclusion.lock();
        discs[0]->move();
        *move_disc = false;
        xclusion.unlock();
      }
    } // close loop while (*advance)
  } // close function kinematics
} // close namespace model
