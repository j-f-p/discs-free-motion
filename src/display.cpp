#include "display.h"
//  implementing Display::animate for display.h
//  implementing Display::renderFrame for display.h
//  using Disc and IntPair
//  using Circ and RenderFillCirc
//  using functions and constants that begin with "SDL_"
    using std::vector;
    using std::unique_ptr;

#include "model.h"
//  using model::retDiscs

#include <chrono>
    using std::chrono::duration_cast;
    using std::chrono::microseconds;
    using std::chrono::milliseconds;
    using std::chrono::system_clock;
    using std::chrono::time_point;

#include <thread>
    using std::this_thread::sleep_for;

namespace {
  const vector<unique_ptr<Disc>> &discs = model::retDiscs();
}

// Animate displays an animation of the simulation.
void Display::animate(unique_ptr<bool> advance) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window*
  sdl_window = SDL_CreateWindow("Disk Simulation", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  renderFrame(); // render initial state

  bool idle = true;
  SDL_Event sdl_event;
  long frame_life = 41; // millisec, so that frame_rate ~= 24 Hz
  time_point<system_clock> frame_start = system_clock::now();
  long frame_age;

  while (*advance) {
    if (idle) { // do nothing unless near end of frame life
      sleep_for(milliseconds(frame_life - 1));
      idle = false;
    } else {
      sleep_for(microseconds(100)); // to moderate CPU
    }

    while( SDL_PollEvent(&sdl_event) != 0 )
      if(sdl_event.type==SDL_QUIT)
        *advance = false;

    frame_age
      = duration_cast<milliseconds>(system_clock::now() - frame_start).count();

    if(frame_age > frame_life) {
      discs[0]->move(screen_height);
      renderFrame();
      idle = true;
      frame_start = system_clock::now();
    }
  }

  // 1/4 sec delay to briefly display the last frame stopped before closing
  SDL_Delay(250);

  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Display::renderFrame() const {
  // Begin render instructions. -----------------------------------------------
  // Clear screen with set render draw colour: a dark grey.
  SDL_SetRenderDrawColor(sdl_renderer, 0xA9, 0xA9, 0xA9, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render two black reference lines that intersect at the screen center.
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderDrawLine(sdl_renderer, 0, 0, screen_width, screen_height);
  SDL_RenderDrawLine(sdl_renderer, screen_width, 0, 0, screen_height);

  // Render a red disc.
  SDL_SetRenderDrawColor(sdl_renderer, 0xC0, 0x00, 0x00, 0xFF);
  RenderFillCirc(sdl_renderer, &discs[0]->circle);
  // End render instructions. -------------------------------------------------

  // Execute render instructions.
  SDL_RenderPresent(sdl_renderer);
}
