#include <SDL2/SDL_render.h>
#include <SDL_circle.h>

int SDL_RenderDrawCircle(SDL_Renderer *const restrict renderer, SDL_Circle const *const restrict circle)
{
    int d, y, x;
    
    d = 3 - (2 * circle->r);
    x = 0;
    y = circle->r;
    
    while (y >= x) {
        if (SDL_RenderDrawPoint(renderer, circle->x + x, circle->y + y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x + y, circle->y + x) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x - x, circle->y + y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x - y, circle->y + x) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x + x, circle->y - y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x + y, circle->y - x) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x - x, circle->y - y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawPoint(renderer, circle->x - y, circle->y - x) < 0)
        {
            return -1;
        }

    
        if (d < 0)
            d = d + (4 * x) + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
    
        x++;
    }
    return 0;
}

int SDL_RenderFillCircle(SDL_Renderer* const restrict renderer, SDL_Circle const* const restrict circle)
{
    int d = 3 - (2 * circle->r);
    int x = 0;
    int y = circle->r;

    while (y >= x) {
        if (SDL_RenderDrawLine(renderer, circle->x - x, circle->y - y, circle->x + x + 1, circle->y - y) < 0)
        {
            return -1;
        }


        if (SDL_RenderDrawLine(renderer, circle->x - x, circle->y + y, circle->x + x + 1, circle->y + y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x - y, circle->y - x, circle->x + y + 1, circle->y - x) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x - y, circle->y + x, circle->x + y + 1, circle->y + x) < 0)
        {
            return -1;
        }

        if (d < 0)
            d = d + (4 * x) + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
    return 0;
}