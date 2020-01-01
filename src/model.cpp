#include "display.h"
//  using display::idle and display::frame_life

#include "model.h"
//  initilizing xclusion, advance and move_discs for model.h
//  implementing addDisc, retDiscs and kinematics for model.h
//  using Disc
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

  const short n_discs{16};
  mutex xclusion;
  bool advance{true}, move_discs{};

  void addDisc(unique_ptr<Disc> disk) {
    discs.push_back(move(disk));
  }

  const vector<unique_ptr<Disc>>& retDiscs() {
    return discs;
  }

  void kinematics() {
    while (advance) {
      if (display::idle)
        sleep_for(milliseconds(display::frame_life - 2)); // to moderate CPU
      else
        sleep_for(microseconds(100)); // to less moderate CPU

      if (move_discs==true) {
        xclusion.lock();
        for( short disc_i=0;  disc_i < n_discs;  ++disc_i )
          discs[disc_i]->move();
        move_discs = false;
        xclusion.unlock();
      }
    } // close loop while (advance)
  } // close function kinematics
} // close namespace model
