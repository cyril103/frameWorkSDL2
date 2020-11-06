#include "drawRects.h"

SDL_Rect rect;
Buffer *buffer;
Vector2 mousePosCliked;
Vector2 mousePos;
Bool isDrawing;
Bool isMoving;
int indexRectToMove;
Vector2 diff;

static void calculRect(void);
static void calculdiff(int index);

void drawRect_init(void)
{
    Graphics_init();
    InputManager_Init();
    buffer = Buffer_empty(sizeof(SDL_Rect));
}
void drawRect_update(void)
{
    if (InputManager_MouseButtonPressed(left))
    {
        isDrawing = True;
        isMoving = False;
        mousePosCliked = InputManager_MousePos();
        SDL_Point p = {mousePosCliked.x, mousePosCliked.y};
        for (int i = 0; i < Buffer_Nb_elem(buffer); ++i)
        {
            if (SDL_PointInRect(&p, Buffer_get(buffer, i)))
            {
                indexRectToMove = i;
                calculdiff(i);
                isDrawing = False;
                isMoving = True;

                break;
            }
        }
    }

    if (InputManager_MouseButtonReleased(left))
    {
        if (isDrawing)
            Buffer_add(buffer, &rect);
        isDrawing = False;
        isMoving = False;
    }
    if (isDrawing)
    {
        mousePos = InputManager_MousePos();
        calculRect();
    }
    if (isMoving)
    {
        mousePos = InputManager_MousePos();
        SDL_Rect *r = Buffer_get(buffer, indexRectToMove);

        r->x = mousePos.x - diff.x;
        r->y = mousePos.y - diff.y;
    }
}
void drawRect_render(void)
{
    if (isDrawing)
        Graphics_draw_rects(&rect, 1, 255, 0, 120, 255);
    if (Buffer_Nb_elem(buffer) > 0)
        Graphics_draw_rects(Buffer_get(buffer, 0), Buffer_Nb_elem(buffer), 255, 0, 120, 255);
}
void drawRect_Release(void)
{
    Buffer_Destroy(&buffer, NULL);
}
static void calculRect(void)
{
    if (mousePos.x >= mousePosCliked.x && mousePos.y <= mousePosCliked.y)
    {
        rect.x = mousePosCliked.x;
        rect.y = mousePos.y;
        rect.w = mousePos.x - mousePosCliked.x;
        rect.h = mousePosCliked.y - mousePos.y;
    }
    if (mousePos.x < mousePosCliked.x && mousePos.y <= mousePosCliked.y)
    {
        rect.x = mousePos.x;
        rect.y = mousePos.y;
        rect.w = mousePosCliked.x - mousePos.x;
        rect.h = mousePosCliked.y - mousePos.y;
    }
    if (mousePos.x < mousePosCliked.x && mousePos.y > mousePosCliked.y)
    {
        rect.x = mousePos.x;
        rect.y = mousePosCliked.y;
        rect.w = mousePosCliked.x - mousePos.x;
        rect.h = mousePos.y - mousePosCliked.y;
    }
    if (mousePos.x >= mousePosCliked.x && mousePos.y > mousePosCliked.y)
    {
        rect.x = mousePosCliked.x;
        rect.y = mousePosCliked.y;
        rect.w = mousePos.x - mousePosCliked.x;
        rect.h = mousePos.y - mousePosCliked.y;
    }
}

static void calculdiff(int index)
{
    SDL_Rect *r = Buffer_get(buffer, index);
    diff = Vector2_Minus(mousePosCliked, Vector2_(r->x, r->y));
}