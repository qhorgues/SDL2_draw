#include <SDL2/SDL_render.h>
#include <SDL_circle.h>
#include <SDL_circleQuarter.h>

static int SDL_RenderFillCircleQuarterLeftUp(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle)
{
    int d = 3 - (2 * circle->r);
    int x = 0;
    int y = circle->r;

    while (y >= x) {
        if (SDL_RenderDrawLine(renderer, circle->x - x, circle->y - y, circle->x, circle->y - y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x - y, circle->y - x, circle->x, circle->y - x) < 0)
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

static int SDL_RenderFillCircleQuarterRightUp(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle)
{
    int d = 3 - (2 * circle->r);
    int x = 0;
    int y = circle->r;

    while (y >= x) {
        if (SDL_RenderDrawLine(renderer, circle->x, circle->y - y, circle->x + x, circle->y - y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x, circle->y - x, circle->x + y, circle->y - x) < 0)
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

static int SDL_RenderFillCircleQuarterLeftDown(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle)
{
    int d = 3 - (2 * circle->r);
    int x = 0;
    int y = circle->r;

    while (y >= x) {
        if (SDL_RenderDrawLine(renderer, circle->x - x, circle->y + y, circle->x, circle->y + y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x - y, circle->y + x, circle->x, circle->y + x) < 0)
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

static int SDL_RenderFillCircleQuarterRightDown(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle)
{
    int d = 3 - (2 * circle->r);
    int x = 0;
    int y = circle->r;

    while (y >= x) {
        if (SDL_RenderDrawLine(renderer, circle->x, circle->y + y, circle->x + x, circle->y + y) < 0)
        {
            return -1;
        }

        if (SDL_RenderDrawLine(renderer, circle->x, circle->y + x, circle->x + y, circle->y + x) < 0)
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

int SDL_RenderFillCircleQuarter(SDL_Renderer* const restrict renderer, SDL_Circle const *const restrict circle, SDL_CircleQuarter const quarter)
{
    switch (quarter)
    {
    case SDL_CIRCLE_QUARTER_LEFT_UP:
        if (SDL_RenderFillCircleQuarterLeftUp(renderer, circle) < 0)
        {
            return -1;
        }
        break;
    case SDL_CIRCLE_QUARTER_RIGHT_UP:
        if (SDL_RenderFillCircleQuarterRightUp(renderer, circle) < 0)
        {
            return -1;
        }
        break;
    case SDL_CIRCLE_QUARTER_LEFT_DOWN:
        if (SDL_RenderFillCircleQuarterLeftDown(renderer, circle) < 0)
        {
            return -1;
        }
        break;
    case SDL_CIRCLE_QUARTER_RIGHT_DOWN:
        if (SDL_RenderFillCircleQuarterRightDown(renderer, circle) < 0)
        {
            return -1;
        }
        break;
    default:
        SDL_SetError("Invalid argument");
        return -1;
    }
    return 0;
}