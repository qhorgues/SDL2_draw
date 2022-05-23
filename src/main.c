#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL_draw.h>

#undef main

int main(void)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    if (0 != SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return -1;
    }
    if (0 != SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer))
    {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    /* SDL_Rect rect = {200, 100, 30, 30}; */
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

    SDL_Circle circle = {100, 100, 50};
    SDL_RenderDrawCircle(renderer, &circle);
    circle.x = 200;
    circle.y = 200;
    SDL_RenderFillCircle(renderer, &circle);

    SDL_Rect rect = {400, 100, 100, 50};
    SDL_RenderFillRoundedRect(renderer, &rect, 15);
    SDL_RenderPresent(renderer);
    
    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}