#ifndef __APP_MANAGER_H__
#define __APP_MANAGER_H__


#include "Graphics.h"
#include "timer.h"
#include "inputManager.h"
#include "texture.h"

typedef struct AppManager {
    /*public methods*/
    void (*run)(void);
    /*public attributs*/
    const int FRAME_RATE;
    /*private attributs*/
    bool mQuit;
    Graphics *mGraphics;
    AssetManager *mAssetMgr;
    InputManager *mInputMgr;
    Timer *mTimer;
    SDL_Event mEvents;


}AppManager;



AppManager *App_instance(void);
void App_realease(void);
void App_run(void);


#endif


