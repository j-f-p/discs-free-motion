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
// using unique_ptr

// Display is a manager of the logic that displays the disk simulation.
class Display {
    SDL_Renderer* sdl_renderer;
    std::vector<std::shared_ptr<Disc>> discs;
    void renderFrame() const;

  public:
    const unsigned short screen_width{480};
    const unsigned short screen_height{480};

    void addDisc(std::shared_ptr<Disc>);
    void animate(std::unique_ptr<bool>);
};

#endif
