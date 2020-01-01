#ifndef DISPLAY_H
#define DISPLAY_H

// Display is a manager of the logic that displays the disk simulation.
namespace display {
  extern bool idle;
  const short screen_width{640};
  const short screen_height{480};
  const short frame_life{41};
    // frame_life is 41 millisec, so that frame_rate ~= 24 Hz

  void animate();
}

#endif
