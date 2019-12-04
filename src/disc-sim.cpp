#include "fillCirc.h"
// includes SDL.h

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  const unsigned short cScreenWidth{480};
  const unsigned short cScreenHeight{480};

  SDL_Window*
  sdl_window = SDL_CreateWindow("Disk Simulation", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, cScreenWidth,
                                cScreenHeight, SDL_WINDOW_SHOWN);

  SDL_Renderer*
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  // Clear (paint) screen with set render draw colour: a dark grey.
  SDL_SetRenderDrawColor(sdl_renderer, 0xA9, 0xA9, 0xA9, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render centered, quarter-screen-sized and filled rectangle dark green.
  SDL_Rect fillRect = {
    cScreenWidth / 4, cScreenHeight / 4, cScreenWidth / 2, cScreenHeight / 2 };
  SDL_SetRenderDrawColor( sdl_renderer, 0x00, 0xA9, 0x00, 0xFF );
  SDL_RenderFillRect( sdl_renderer, &fillRect );

  // Render centered, quarter-screen-sized and filled circl dark red.
  SDL_SetRenderDrawColor( sdl_renderer, 0xA9, 0x00, 0x00, 0xFF );
  Circ circ = { cScreenWidth / 2, cScreenHeight / 2, cScreenHeight / 4 };
  RenderFillCirc( sdl_renderer, &circ );

  // Apply Clear, FillRect and FillCirc, in that order.
  SDL_RenderPresent(sdl_renderer);

  SDL_Delay(2000); // 2 sec delay

  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}
