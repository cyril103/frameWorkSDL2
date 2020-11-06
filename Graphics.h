#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#define GRAPHICS_WIDTH 1024
#define GRAPHICS_HEIGHT 576
#define GRAPHICS_TITLE "testsdl"


#include <stdlib.h>
#include <stdio.h>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "util.h"




void Graphics_init(void);
void Graphics_release(void);
Bool Graphics_isInitialized(void);
void Graphics_clearBackBuffer(void);
void Graphics_render(void);
void Graphics_draw_rects(SDL_Rect *rects ,int n,Uint8 r, Uint8 g, Uint8 b, Uint8 a);
SDL_Texture* Graphics_loadTexture(char const * path);
void Graphics_drawTexture(SDL_Texture* tex);
#endif