#include "damier.h"


Buffer *rectsgreen;
Buffer *rectsred;
SDL_Rect rect = {0, 0, 50, 50};
SDL_Rect hiddenRect = {-50, -50, 50, 50};
Vector2 vec2;

void damier_release(void)
{
    Buffer_Destroy(&rectsgreen,NULL);
    Buffer_Destroy(&rectsred, NULL);
}

void damier_init(void)
{
    Graphics_init();
    InputManager_Init();
    rectsgreen = Buffer_empty(sizeof(SDL_Rect));
    rectsred = Buffer_empty(sizeof(SDL_Rect));

    for (int y = 0, j = 0; y < 500; y += 50, j++)
    {
        for (int x = 0, i = 0; x < 500; x += 50, i++)
        {

            rect.x = x;
            rect.y = y;
            Buffer_add(rectsred, &rect);
            if ((i + j) % 2 == 0)
                Buffer_add(rectsgreen, &rect);
            else
                Buffer_add(rectsgreen, &hiddenRect);
        }
    }
}
void damier_update(void)

{
    if(InputManager_MouseButtonPressed(left)){
        InputManager_MousePos(&vec2);

    
    int index = ((int)vec2.y / 50 * 10 + (int)vec2.x / 50);
    SDL_Rect *elem = Buffer_get(rectsgreen, index);
    if (elem->x == -50)
    {
        Buffer_update(rectsgreen, index, Buffer_get(rectsred, index));
    }
    else
    {
        Buffer_update(rectsgreen, index, &hiddenRect);
    }
    }
}
void damier_render(void)
{

    Graphics_draw_rects(Buffer_get(rectsred,0), Buffer_Nb_elem(rectsred),
                        255, 0, 0, 255);
    Graphics_draw_rects(Buffer_get(rectsgreen,0), Buffer_Nb_elem(rectsgreen),
                        0, 255, 0, 255);
}