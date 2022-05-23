#ifndef SDL_circleQuarter_h_
#define SDL_circleQuarter_h_

#include "SDL_circle.h"

typedef enum SDL_CircleQuarter
{
    SDL_CIRCLE_QUARTER_LEFT_UP,
    SDL_CIRCLE_QUARTER_RIGHT_UP,
    SDL_CIRCLE_QUARTER_LEFT_DOWN,
    SDL_CIRCLE_QUARTER_RIGHT_DOWN,
} SDL_CircleQuarter;


extern int SDL_RenderFillCircleQuarter(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle, SDL_CircleQuarter const quarter);

#endif