#include "inputManager.h"



static InputManager *s_instance = NULL;
static InputManager *InputManager_new(void);

static InputManager *InputManager_new(void){
	InputManager model = {
		.KeyDown = InputManager_KeyDown,
		.KeyPressed = InputManager_KeyPressed,
		.KeyReleased = InputManager_KeyReleased,
		.MouseButtonDown = InputManager_MouseButtonDown,
		.MouseButtonPressed = InputManager_MouseButtonPressed,
		.MouseButtonReleased = InputManager_MouseButtonReleased,
		.MousePos = InputManager_MousePos,
		.Update = InputManager_Update,
		.UpdatePrevInput = InputManager_UpdatePrevInput,
		

	};
	s_instance = memory_Alloc(sizeof(InputManager));
	memcpy(s_instance,&model,sizeof(InputManager));
	s_instance->mKeyboardState = SDL_GetKeyboardState(&(s_instance->mKeyLength));
	s_instance->mPrevKeyboardState = memory_Alloc(s_instance->mKeyLength * sizeof(Uint8));
	memcpy(s_instance->mPrevKeyboardState,s_instance->mKeyboardState,s_instance->mKeyLength);
	return s_instance;
}

InputManager *InputManager_Instance(void)
{
	
	if (s_instance == NULL)
		s_instance = InputManager_new();
	return s_instance;

	
}
void InputManager_Release(void)
{
	memory_Free(s_instance->mPrevKeyboardState,s_instance->mKeyLength * sizeof(Uint8));
	s_instance->mPrevKeyboardState = NULL;
	memory_Free(s_instance,sizeof(InputManager));
	s_instance = NULL;
}
bool InputManager_KeyDown(SDL_Scancode scanCode)
{
	return (s_instance->mKeyboardState[scanCode] != 0);
}
bool InputManager_KeyPressed(SDL_Scancode scanCode)
{
	return (s_instance->mPrevKeyboardState[scanCode]) == 0 && (s_instance->mKeyboardState[scanCode] != 0);
}
bool InputManager_KeyReleased(SDL_Scancode scanCode)
{
	return (s_instance->mPrevKeyboardState[scanCode] != 0) && (s_instance->mKeyboardState[scanCode] == 0);
}
bool InputManager_MouseButtonDown(INPUT_MANAGER_MOUSE_BUTTON button)
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

	return ((s_instance->mMouseState & mask) != 0);
}

bool InputManager_MouseButtonPressed(INPUT_MANAGER_MOUSE_BUTTON button)
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

	return ((s_instance->mPrevMouseState & mask) == 0) && ((s_instance->mMouseState & mask) != 0);
}

bool InputManager_MouseButtonReleased(INPUT_MANAGER_MOUSE_BUTTON button)
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

	return ((s_instance->mPrevMouseState & mask) != 0) && ((s_instance->mMouseState & mask) == 0);
}

Vector2 InputManager_MousePos(void)
{
	return Vector2_((float)s_instance->mMouseXPos,(float)s_instance->mMouseYPos);

}

void InputManager_Update(void)
{
	s_instance->mMouseState = SDL_GetMouseState(&s_instance->mMouseXPos, &s_instance->mMouseYPos);
}

void InputManager_UpdatePrevInput(void)
{

	memcpy(s_instance->mPrevKeyboardState,s_instance->mKeyboardState,s_instance->mKeyLength);
	s_instance->mPrevMouseState = s_instance->mMouseState;
}