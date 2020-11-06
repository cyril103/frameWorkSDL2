#include "App_manager.h"
#include "string.h"


#define FRAME_RATE 60
Bool quit = False;
SDL_Event events;

static void earlyUpdate(void);
static void update(void);
static void lateUpdate(void);
static void render(void);

static Texture *tex;

void App_realease(void)
{   Texture_Destroy(&tex);
    AssetManager_Released();
    InputManager_Release();
    timer_release();
    Graphics_release();
       
}
void App_init(void)
{

    Graphics_init();
    if (!Graphics_isInitialized())
    {
        quit = True;
    }

    timer_init();

    InputManager_Init();
    AssetManager_Init();

    tex = Texture_("spriteSheet.png");
    Texture *tex2 = Texture_("spriteSheet.png");
    Texture *tex3 = Texture_("spriteSheet.png");

    Texture_Destroy(&tex2);
    Texture_Destroy(&tex3);
        

    
}

static void earlyUpdate(void)
{
    InputManager_Update();
    timer_reset();
}

static void update(void)
{
    
    if(InputManager_KeyPressed(SDL_SCANCODE_ESCAPE))
        quit = True;
}

static void lateUpdate(void)
{
    InputManager_UpdatePrevInput();
}

static void render(void)
{

    Graphics_clearBackBuffer();
    Texture_Render(tex);    

    Graphics_render();
}

void App_run(void)
{

    while (!quit)
    {

        timer_update();

        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
            {
                quit = True;
            }

            
        }

        if (timer_deltaTime() >= (1.0f / FRAME_RATE))
        {

            earlyUpdate();
            update();
            lateUpdate();
            render();
        }
    }
}