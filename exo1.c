
#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include"memory.h"
#include"buffer.h"

#define RECT_LARGEUR 50
#define RECT_HAUTEUR 50

void drawRectangles(SDL_Renderer *renderer, Buffer *buffer)
{

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRects(renderer, Buffer_get(buffer,0) ,Buffer_Nb_elem(buffer));
}

void afficheInfoRect(Buffer *buffer, SDL_Window *window)
{
    SDL_Rect *rectangles = Buffer_get(buffer,0);
    int x, y, w, h;
    if (Buffer_Nb_elem(buffer) == 0)
    {
        printf("Aucun rectangle\n");
    }
    else
    {
        for (int i = 0; i < Buffer_Nb_elem(buffer); i++)
        {
            x = rectangles[i].x;
            y = rectangles[i].y;

            int H;
            int W;
            SDL_GetWindowSize(window, &W, &H);
            if (x < 0)
                w = x + RECT_LARGEUR;
            else if (x + RECT_LARGEUR > W)
                w = W - x;
            else
                w = RECT_LARGEUR;
            if (y < 0)
                h = y + RECT_HAUTEUR;
            else if (y + RECT_HAUTEUR > H)
                h = H - y;
            else
                h = RECT_HAUTEUR;

            printf("Rectangle %d : x=%d ; y=%d ; w=%d ; h=%d\n",
                   i, x, y, w, h);
        }
    }
}

int main(int argc, char **argv)

{
    (void) argc;
    (void) argv;
    Buffer *rects = Buffer_empty(sizeof(SDL_Rect));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("exo1",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          600, 400,
                                          SDL_WINDOW_RESIZABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_bool quit = SDL_FALSE;
    
    SDL_Rect rect = {0, 0, RECT_LARGEUR, RECT_HAUTEUR};

    while (!quit)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;

            case SDL_MOUSEBUTTONDOWN:

                rect.x = event.button.x - RECT_LARGEUR / 2;
                rect.y = event.button.y - RECT_HAUTEUR / 2;

                Buffer_add(rects, &rect);
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_l)
                    afficheInfoRect(rects, window);
                if (event.key.keysym.sym == SDLK_ESCAPE)
                    quit = SDL_TRUE;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        drawRectangles(renderer, rects);

        SDL_RenderPresent(renderer);
        
    }

    Buffer_Destroy(&rects,NULL);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    check_if_memory_leak();

    return EXIT_SUCCESS;
}