#ifndef _TIMER_H
#define _TIMER_H

#include"SDL2/SDL.h"
#include <string.h>
#include "memory.h"

typedef struct Timer{
    /*public methods*/
    void (*reset)(void);
    float (*deltaTime)(void);
    void (*setTimeScale)(float t);
    float (*timeScale)(void);
    void (*update)(void);
    /*private attibuts*/
    unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDelataTime;
    float mTimeScale;
}Timer;

Timer *timer_instance(void);
void timer_release(void);

void timer_reset(void);
float timer_deltaTime(void);
void timer_setTimeScale(float t);
float timer_timeScale(void);
void timer_update(void);



#endif