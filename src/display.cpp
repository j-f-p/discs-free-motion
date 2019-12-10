#include "display.h"
//  implementing Display::animate for display.h
//  implementing Display::renderFrame for display.h
//  using Disc and IntPair
//  using Circ and RenderFillCirc
//  using functions and constants that begin with "SDL_"
    using std::vector;
    using std::shared_ptr;


#include <chrono>
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    using std::chrono::system_clock;
    using std::chrono::time_point;

#include <thread>
    using std::this_thread::sleep_for;

// Animate displays an animation of the simulation.
void Display::animate() {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window*
  sdl_window = SDL_CreateWindow("Disk Simulation", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  bool advance = true;
  long frame_life = 41; // millisec, so that frame_rate ~= 24 Hz

  time_point<system_clock> frame_start = system_clock::now();
  long frame_age;

  while (advance) {
    sleep_for(milliseconds(1)); // to moderate CPU

    frame_age
      = duration_cast<milliseconds>(system_clock::now() - frame_start).count();

    if(frame_age >= frame_life) {
      discs[0]->move();
      renderFrame();
      advance = false;
    }
    frame_start = system_clock::now();
  }

  SDL_Delay(2000); // 2 sec delay

  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Display::renderFrame() const {
  // Begin render instructions. -----------------------------------------------
  // Clear (paint) screen with set render draw colour: a dark grey.
  SDL_SetRenderDrawColor(sdl_renderer, 0xA9, 0xA9, 0xA9, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Set render draw color to black.
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  // diagonal reference lines
  SDL_RenderDrawLine(sdl_renderer, 0, 0, screen_width, screen_height);
  SDL_RenderDrawLine(sdl_renderer, screen_width, 0, 0, screen_height);

  // Set render draw color to a red with ~50% opacity.
  SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);
  SDL_SetRenderDrawColor(sdl_renderer, 0xC0, 0x00, 0x00, 0x80);
  Circ circ = {discs[0]->position, discs[0]->radius};
  // Circ circ = {  // static_cast here appeases compiler warning
    // discs[0]->position, static_cast<unsigned short>(screen_height/4) };
  RenderFillCirc(sdl_renderer, &circ);
  // End render instructions. -------------------------------------------------

  // Execute render instructions.
  SDL_RenderPresent(sdl_renderer);
}
