#include "model.h"
//  using Disc
    using std::unique_ptr;
    using std::vector;

#include <utility>
    using std::move;

namespace model {
  namespace {
    vector<unique_ptr<Disc>> discs;
  }

  void addDisc(unique_ptr<Disc> disk) {
    discs.push_back(move(disk));
  }

  const vector<unique_ptr<Disc>>& retDiscs() {
    return discs;
  }
}
