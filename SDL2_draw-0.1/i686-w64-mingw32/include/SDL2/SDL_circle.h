#ifndef SDL_circle_h_
#define SDL_circle_h_
#include <SDL2/SDL_render.h>

typedef struct SDL_Circle
{
    int x, y;
    int r;
} SDL_Circle;


extern int SDL_RenderFillCircle(SDL_Renderer* const restrict renderer, SDL_Circle const* const restrict circle);
extern int SDL_RenderDrawCircle(SDL_Renderer *const restrict renderer, SDL_Circle const *const restrict circle);

#endif