#ifndef DISPLAY_H
#define DISPLAY_H

// Display is a manager of the logic that displays the disk simulation.
namespace display {
  extern bool idle;
  extern const short screen_width;
  extern const short screen_height;
  extern const short frame_life;
  void animate();
}

#endif
