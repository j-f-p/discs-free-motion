#ifndef DISPLAY_H
#define DISPLAY_H

#include "disc.h"
// using Disc

#include "fillCirc.h"
// using SDL_Renderer

#include <vector>
// using vector

#include <memory>
// using shared_ptr

// Display is a manager of the logic that displays the disk simulation.
class Display {
    SDL_Renderer* sdl_renderer;
    std::vector<std::shared_ptr<Disc>> discs;

  public:
    const unsigned short screen_width{480};
    const unsigned short screen_height{480};

    void setDiscs(std::vector<std::shared_ptr<Disc>>& initDiscs) {
      discs = initDiscs;
    }

    void animate();
    void renderFrame() const;
};

#endif
