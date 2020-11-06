#ifndef _TIMER_H
#define _TIMER_H

#include"SDL2/SDL.h"

void timer_init(void);
void timer_release(void);
void timer_reset(void);
float timer_deltaTime(void);
void timer_setTimeScale(float t);
float timer_timeScale(void);
void timer_update(void);



#endif