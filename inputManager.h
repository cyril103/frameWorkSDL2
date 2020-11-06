#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include "SDL2/SDL.h"
#include <stdbool.h>
#include "memory.h"
#include <string.h>
#include "mathHelper.h"



typedef enum INPUT_MANAGER_MOUSE_BUTTON { left = 0,
 right, middle, back, forward }INPUT_MANAGER_MOUSE_BUTTON;

 typedef struct InputManager{
     /*public methods*/
    bool (*KeyDown)(SDL_Scancode scanCode);
    bool (*KeyPressed)(SDL_Scancode scanCode);
    bool (*KeyReleased)(SDL_Scancode scanCode);
    bool (*MouseButtonDown)(INPUT_MANAGER_MOUSE_BUTTON button);
    bool (*MouseButtonPressed)(INPUT_MANAGER_MOUSE_BUTTON button);
    bool (*MouseButtonReleased)(INPUT_MANAGER_MOUSE_BUTTON button);
    Vector2 (*MousePos)(void);
    void (*Update)(void);
    void (*UpdatePrevInput)(void);
    /*private attributs*/
    Uint8 *mPrevKeyboardState;
    const Uint8 *mKeyboardState;
    int mKeyLength;
    Uint32 mPrevMouseState;
    Uint32 mMouseState;
    int mMouseXPos;
    int mMouseYPos;

 }InputManager;

InputManager *InputManager_Instance(void);
void InputManager_Release(void);

bool InputManager_KeyDown(SDL_Scancode scanCode);
bool InputManager_KeyPressed(SDL_Scancode scanCode);
bool InputManager_KeyReleased(SDL_Scancode scanCode);
bool InputManager_MouseButtonDown(INPUT_MANAGER_MOUSE_BUTTON button);
bool InputManager_MouseButtonPressed(INPUT_MANAGER_MOUSE_BUTTON button);
bool InputManager_MouseButtonReleased(INPUT_MANAGER_MOUSE_BUTTON button);
Vector2 InputManager_MousePos(void);
void InputManager_Update(void);
void InputManager_UpdatePrevInput(void);

#endif
