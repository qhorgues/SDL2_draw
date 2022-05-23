#include <SDL_circleQuarter.h>

#define CIRCLE(x, y, r) (SDL_Circle){x, y, r}

SDL_Texture* SDL_RenderFillRoundedRect(SDL_Renderer* const restrict renderer, SDL_Rect const* const restrict rect, int radius)
{


    if (radius > 0)
    {
        SDL_Circle angleRect = {0, 0, 0};
        if (radius >= rect->w/2 && radius <= rect->h/2)
        {
            angleRect = CIRCLE(rect->x + (rect->w/2), rect->y + (rect->w/2), (rect->w/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_UP);

            angleRect = CIRCLE(rect->x + rect->w - (rect->w/2)-1, rect->y + (rect->w/2), (rect->w/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_UP);

            angleRect = CIRCLE(rect->x + (rect->w/2), rect->y + rect->h - (rect->w/2)-1, (rect->w/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_DOWN);

            angleRect = CIRCLE( rect->x + rect->w - (rect->w/2)-1, rect->y + rect->h - (rect->w/2)-1, (rect->w/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_DOWN);

            SDL_Rect rectPart = {rect->x, rect->y + (rect->w/2), rect->w, rect->h - rect->w};
            SDL_RenderFillRect(renderer, &rectPart);
        }
        else if (radius >= rect->h/2 && radius <= rect->w/2)
        {
            
            angleRect = CIRCLE(rect->x + (rect->h/2), rect->y + (rect->h/2), (rect->h/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_UP);
            
            angleRect = CIRCLE(rect->x + rect->w - (rect->h/2)-1, rect->y + (rect->h/2), (rect->h/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_UP);
            
            angleRect = CIRCLE(rect->x + (rect->h/2), rect->y + rect->h - (rect->h/2)-1, (rect->h/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_DOWN);
            
            angleRect = CIRCLE(rect->x + rect->w - (rect->h/2)-1, rect->y + rect->h - (rect->h/2)-1, (rect->h/2));
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_DOWN);

            SDL_Rect rectPart = {rect->x + (rect->h/2), rect->y, rect->w - rect->h, rect->h};
            SDL_RenderFillRect(renderer, &rectPart);
        }
        else if (radius >= rect->w/2 && radius >= rect->h/2)
        {
            angleRect = CIRCLE(rect->x + rect->w/2, rect->y + rect->h/2, (rect->w > rect->h) ? rect->h/2 : rect->w/2);
            SDL_RenderFillCircle(renderer, &angleRect);
        }
        else
        {
            
            angleRect = CIRCLE(rect->x + radius, rect->y + radius, radius);
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_UP);
            
            angleRect = CIRCLE(rect->x + rect->w - radius-1, rect->y + radius, radius);
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_UP);
            
            angleRect = CIRCLE(rect->x + radius, rect->y + rect->h - radius-1, radius);
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_LEFT_DOWN);
            
            angleRect = CIRCLE(rect->x + rect->w - radius-1, rect->y + rect->h - radius-1, radius);
            SDL_RenderFillCircleQuarter(renderer, &angleRect, SDL_CIRCLE_QUARTER_RIGHT_DOWN);

            SDL_Rect rectPart1 = {rect->x + radius, rect->y, rect->w - 2*radius, rect->h};
            SDL_RenderFillRect(renderer, &rectPart1);
            SDL_Rect rectPart2 = {rect->x, rect->y+radius, rect->w, rect->h - 2*radius};
            SDL_RenderFillRect(renderer, &rectPart2);
        }
    }
    else
    {
        SDL_RenderFillRect(renderer, rect);
    }
    SDL_SetRenderTarget(renderer, NULL);
    return NULL;
}