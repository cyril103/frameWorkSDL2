#include "inputManager.h"


Uint8 *mPrevKeyboardState;
const Uint8 *mKeyboardState;
int mKeyLength;
Uint32 mPrevMouseState;
Uint32 mMouseState;
int mMouseXPos;
int mMouseYPos;

void InputManager_Init(void)
{
	static Bool isInit = False;
	if (isInit)
		return;
	mKeyboardState = SDL_GetKeyboardState(&mKeyLength);
	mPrevKeyboardState = memory_Alloc(mKeyLength * sizeof(Uint8));
	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
	isInit = True;
}
void InputManager_Release(void)
{
	memory_Free(mPrevKeyboardState, mKeyLength * sizeof(Uint8));
	mPrevKeyboardState = NULL;
}
Bool InputManager_KeyDown(SDL_Scancode scanCode)
{
	return (mKeyboardState[scanCode] != 0);
}
Bool InputManager_KeyPressed(SDL_Scancode scanCode)
{
	return (mPrevKeyboardState[scanCode]) == 0 && (mKeyboardState[scanCode] != 0);
}
Bool InputManager_KeyReleased(SDL_Scancode scanCode)
{
	return (mPrevKeyboardState[scanCode] != 0) && (mKeyboardState[scanCode] == 0);
}
Bool InputManager_MouseButtonDown(INPUT_MANAGER_MOUSE_BUTTON button)
{
	Uint32 mask = 0;

	switch (button)
	{

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return ((mMouseState & mask) != 0);
}

Bool InputManager_MouseButtonPressed(INPUT_MANAGER_MOUSE_BUTTON button)
{
	Uint32 mask = 0;

	switch (button)
	{

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return ((mPrevMouseState & mask) == 0) && ((mMouseState & mask) != 0);
}

Bool InputManager_MouseButtonReleased(INPUT_MANAGER_MOUSE_BUTTON button)
{
	Uint32 mask = 0;

	switch (button)
	{

	case left:

		mask = SDL_BUTTON_LMASK;
		break;

	case right:

		mask = SDL_BUTTON_RMASK;
		break;

	case middle:

		mask = SDL_BUTTON_MMASK;
		break;

	case back:

		mask = SDL_BUTTON_X1MASK;
		break;

	case forward:

		mask = SDL_BUTTON_X2MASK;
		break;
	}

	return ((mPrevMouseState & mask) != 0) && ((mMouseState & mask) == 0);
}

Vector2 InputManager_MousePos(void)
{
	return Vector2_((float)mMouseXPos,(float)mMouseYPos);

}

void InputManager_Update(void)
{
	mMouseState = SDL_GetMouseState(&mMouseXPos, &mMouseYPos);
}

void InputManager_UpdatePrevInput(void)
{

	memcpy(mPrevKeyboardState, mKeyboardState, mKeyLength);
	mPrevMouseState = mMouseState;
}