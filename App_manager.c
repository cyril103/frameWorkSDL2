#include "App_manager.h"
#include "string.h"



static AppManager *s_instance = NULL;

static AppManager *AppManager_new(void);
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

    memory_Free(s_instance,sizeof(AppManager));
       
}

static AppManager *AppManager_new(void){
    
    AppManager model = {
        .run = App_run,
        .FRAME_RATE = 60,
        .mQuit = false,
        
    };
    s_instance = memory_Alloc(sizeof(AppManager));
    memcpy(s_instance,&model,sizeof(AppManager));
    s_instance->mGraphics = Graphics_instance();
    if (!Graphics_isInitialized())
    {
        s_instance->mQuit = true;
    }

    s_instance->mTimer = timer_instance();

    s_instance->mInputMgr = InputManager_Instance();
    s_instance->mAssetMgr = AssetManager_Instance();

    tex = Texture_("spriteSheet.png");



    return s_instance;
}



AppManager *App_instance(void)
{   
    if(s_instance == NULL)
        s_instance = AppManager_new();
    
    return s_instance;       

    
}

static void earlyUpdate(void)
{
    InputManager_Update();
    timer_reset();
}

static void update(void)
{
    
    if(InputManager_KeyPressed(SDL_SCANCODE_ESCAPE))
        s_instance->mQuit = true;
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

    while (!(s_instance->mQuit))
    {

        timer_update();

        while (SDL_PollEvent(&(s_instance->mEvents)))
        {
            if (s_instance->mEvents.type == SDL_QUIT)
            {
                s_instance->mQuit = true;
            }

            
        }

        if (timer_deltaTime() >= (1.0f / s_instance->FRAME_RATE))
        {

            earlyUpdate();
            update();
            lateUpdate();
            render();
        }
    }
}