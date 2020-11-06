#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include "SDL2/SDL.h"
#include "util.h"
#include "memory.h"
#include <string.h>
#include "mathHelper.h"


typedef enum INPUT_MANAGER_MOUSE_BUTTON { left = 0,
 right, middle, back, forward }INPUT_MANAGER_MOUSE_BUTTON;

void InputManager_Init(void);
void InputManager_Release(void);
Bool InputManager_KeyDown(SDL_Scancode scanCode);
Bool InputManager_KeyPressed(SDL_Scancode scanCode);
Bool InputManager_KeyReleased(SDL_Scancode scanCode);
Bool InputManager_MouseButtonDown(INPUT_MANAGER_MOUSE_BUTTON button);
Bool InputManager_MouseButtonPressed(INPUT_MANAGER_MOUSE_BUTTON button);
Bool InputManager_MouseButtonReleased(INPUT_MANAGER_MOUSE_BUTTON button);
Vector2 InputManager_MousePos(void);
void InputManager_Update(void);
void InputManager_UpdatePrevInput(void);

#endif
