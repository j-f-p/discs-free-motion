#include "model.h"
//  using Disc
    using std::shared_ptr;
    using std::unique_ptr;
    using std::vector;

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

  shared_ptr<bool> advance(new bool{true}), move_disc(new bool{});
  Display display;

  void addDisc(unique_ptr<Disc> disk) {
    discs.push_back(move(disk));
  }

  const vector<unique_ptr<Disc>>& retDiscs() {
    return discs;
  }

  void kinematics() {
    while (*advance) {
      // if (display.idle) // do nothing unless near end of frame life
      //   continue;
      if (display.idle) {
        sleep_for(milliseconds(display.frame_life - 1)); // to moderate CPU
      } else {
        sleep_for(microseconds(100)); // to less moderate CPU
      }
      // sleep_for(microseconds(50));

      if (*move_disc==true) {
        discs[0]->move(display.screen_height);
        *move_disc = false;
      }
    }
  } // close function kinematics
} // close namespace model
