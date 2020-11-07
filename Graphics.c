#include "Graphics.h"

//The Width of the game's window
static const int SCREEN_WIDTH = 800;
//The Height of the game's window
static const int SCREEN_HEIGHT = 600;
//The title of the game's window
static const char *WINDOW_TITLE = "QuickSDL";

static Graphics *s_instance = NULL;
static bool s_initialized = false;

static bool init(void);
static void DrawTexture(SDL_Texture *tex, SDL_Rect *clip, SDL_Rect *rend, float angle, SDL_RendererFlip flip);
static Graphics *Graphics_new(void);

static Graphics *Graphics_new(void)
{
    Graphics model = {
        .clearBackBuffer = Graphics_clearBackBuffer,
        .render = Graphics_render,
        .drawRects = Graphics_draw_rects,
        .loadTexture = Graphics_loadTexture,
        .SCREEN_WIDTH = SCREEN_WIDTH,
        .SCREEN_HEIGHT = SCREEN_HEIGHT,
        .WINDOW_TITLE = WINDOW_TITLE,

    };
    s_instance = memory_Alloc(sizeof(Graphics));
    memcpy(s_instance, &model, sizeof(Graphics));
    s_initialized = init();
    return s_instance;
}

Graphics *Graphics_instance(void)
{

    if (s_instance == NULL)
    {
        s_instance = Graphics_new();
    }

    return s_instance;
}
void Graphics_release(void)
{

    SDL_DestroyWindow(s_instance->m_window);
    s_instance->m_window = NULL;
    SDL_DestroyRenderer(s_instance->m_renderer);
    s_instance->m_renderer = NULL;

    memory_Free(s_instance, sizeof(Graphics));
    s_instance = NULL;

    IMG_Quit();
    SDL_Quit();
}
bool Graphics_isInitialized(void)
{
    return s_initialized;
}

static bool init(void)
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {

        printf("SDL Initialization Error: %s\n", SDL_GetError());
        return false;
    }

    s_instance->m_window = SDL_CreateWindow(WINDOW_TITLE,
                                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                            SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (s_instance->m_window == NULL)
    {
        printf("Window Creation Error: %s\n", SDL_GetError());
        return false;
    }

    s_instance->m_renderer = SDL_CreateRenderer(s_instance->m_window, -1, SDL_RENDERER_ACCELERATED);

    if (s_instance->m_renderer == NULL)
    {
        printf("Renderer Creation Error: %s\n", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(s_instance->m_renderer, 0, 0, 0, 255);

    int flags = IMG_INIT_PNG;
    if (!(IMG_Init(flags) & flags))
    {

        printf("IMG Initialization Error: %s\n", IMG_GetError());
        return false;
    }

    return true;
}

void Graphics_clearBackBuffer(void)
{
    SDL_SetRenderDrawColor(s_instance->m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(s_instance->m_renderer);
}
void Graphics_render(void)
{
    SDL_RenderPresent(s_instance->m_renderer);
}

void Graphics_draw_rects(SDL_Rect *rects, int n, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_SetRenderDrawColor(s_instance->m_renderer, r, g, b, a);
    SDL_RenderFillRects(s_instance->m_renderer, rects, n);
}

SDL_Texture *Graphics_loadTexture(char const *path)
{
    SDL_Texture *tex = NULL;

    //load the image onto a surface
    SDL_Surface *surface = IMG_Load(path);
    //Handling image loading errors
    if (surface == NULL)
    {

        printf("Image Load Error: Path(%s) - Error(%s)\n", path, IMG_GetError());
        return tex;
    }
    //Converting the surface into a texture to be able to render it using the renderer
    tex = SDL_CreateTextureFromSurface(s_instance->m_renderer, surface);
    //Handling texture creation errors
    if (tex == NULL)
    {

        printf("Create Texture Error: %s\n", SDL_GetError());
        return tex;
    }

    //free the surface since only the texture is needed
    SDL_FreeSurface(surface);

    return tex;
}

void Graphics_drawTexture(SDL_Texture *tex)
{
    DrawTexture(tex, NULL, NULL, 0.0f, SDL_FLIP_NONE);
}
static void DrawTexture(SDL_Texture *tex, SDL_Rect *clip, SDL_Rect *rend, float angle, SDL_RendererFlip flip)
{
    SDL_RenderCopyEx(s_instance->m_renderer, tex, clip, rend, angle, NULL, flip);
}
