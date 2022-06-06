#ifndef SDL_circle_h_
#define SDL_circle_h_

typedef struct SDL_Circle
{
    int x, y;
    int r;
} SDL_Circle;


extern DECLSPEC int SDLCALL SDL_RenderFillCircle(SDL_Renderer* const restrict renderer, SDL_Circle const* const restrict circle);
extern DECLSPEC int SDLCALL SDL_RenderDrawCircle(SDL_Renderer *const restrict renderer, SDL_Circle const *const restrict circle);

#endif