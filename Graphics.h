#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "memory.h"

typedef struct Graphics{
    /*public methods*/
    void (*clearBackBuffer)(void);
    void (*render)(void);
    void (*drawRects)(SDL_Rect *rects ,int n,Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    SDL_Texture* (*loadTexture)(char const * path);
    void (*drawTexture)(SDL_Texture* tex);
    /*public attributs*/
    const int SCREEN_WIDTH;
    const int SCREEN_HEIGHT;
    const char* WINDOW_TITLE;
    /*private attributs*/
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
}Graphics;




Graphics *Graphics_instance(void);
void Graphics_release(void);

bool Graphics_isInitialized(void);
void Graphics_clearBackBuffer(void);
void Graphics_render(void);
void Graphics_draw_rects(SDL_Rect *rects ,int n,Uint8 r, Uint8 g, Uint8 b, Uint8 a);
SDL_Texture* Graphics_loadTexture(char const * path);
void Graphics_drawTexture(SDL_Texture* tex);
#endif