#include "SDL.h"

int main() {
  SDL_Init(SDL_INIT_VIDEO);

  const unsigned short cScreenWidth{640};   // old school standard definition
  const unsigned short cScreenHeight{480};  // SD 480p, AR = 4:3

  SDL_Window*
  sdl_window = SDL_CreateWindow("Disk Simulation", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, cScreenWidth,
                                cScreenHeight, SDL_WINDOW_SHOWN);

  SDL_Renderer*
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

	// Clear (paint) screen with set render draw colour: a dark grey.
  SDL_SetRenderDrawColor(sdl_renderer, 0xA9, 0xA9, 0xA9, 0xA9);
	SDL_RenderClear(sdl_renderer);

	// Render centered, quarter-screen-sized and filled rectangle dark green.
	SDL_Rect fillRect = {
    cScreenWidth / 4, cScreenHeight / 4, cScreenWidth / 2, cScreenHeight / 2 };
	SDL_SetRenderDrawColor( sdl_renderer, 0x00, 0xA9, 0x00, 0xFF );
	SDL_RenderFillRect( sdl_renderer, &fillRect );

  // Apply Clear and FillRect, in that order.
  SDL_RenderPresent(sdl_renderer);

  SDL_Delay(3000); // 2 sec delay

	SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}
