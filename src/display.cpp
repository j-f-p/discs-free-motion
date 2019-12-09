#include "display.h"
//  implementing Display::animate for display.h
//  using Disc and IntPair
    using std::vector;
    using std::shared_ptr;

#include "fillCirc.h"
//  using Circ and RenderFillCirc
//  using functions and constants that begin with "SDL_"

// Animate displays an animation of the simulation.
void Display::animate() const {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window*
  sdl_window = SDL_CreateWindow("Disk Simulation", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  SDL_Renderer*
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  bool advance = true;

  while (advance) {
    // Add render instructions.

    // Clear (paint) screen with set render draw colour: a dark grey.
    SDL_SetRenderDrawColor(sdl_renderer, 0xA9, 0xA9, 0xA9, 0xFF);
    SDL_RenderClear(sdl_renderer);

    // Set render draw color to a dark red.
    SDL_SetRenderDrawColor( sdl_renderer, 0xA9, 0x00, 0x00, 0xFF );
    // diagonal reference line
    SDL_RenderDrawLine(sdl_renderer, 0, 0, screen_width, screen_height);

    Circ circ = {  // static_cast here appeases compiler warning
      discs[0]->position, static_cast<unsigned short>(screen_height/4) };
    RenderFillCirc( sdl_renderer, &circ );

    // Execute render instructions.
    SDL_RenderPresent(sdl_renderer);

    advance = false;
    SDL_Delay(2000); // 2 sec delay

    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
  }
}
