#ifndef DISPLAY_H
#define DISPLAY_H

#include "renderFillCirc.h"
// using SDL_Renderer

#include <vector>
// using vector

#include <memory>
// using shared_ptr

// Display is a manager of the logic that displays the disk simulation.
class Display {
    SDL_Renderer* sdl_renderer;
    void renderFrame() const;

  public:
    bool idle{true};
    const short screen_width{480};
    const short screen_height{480};
    const short frame_life{41};
      // frame_life is 41 millisec, so that frame_rate ~= 24 Hz
    void animate();
};

#endif
