#include"timer.h"

unsigned int startTicks;
unsigned int elapsedTicks;
float deltaTime;
float timeScale;
int isInit = 0;

void timer_init(void){
    if(isInit) return;
    isInit = 1;
    timer_reset();
    timeScale = 1.0f;
    elapsedTicks = 0;
    deltaTime = 0.0f;
    
}
void timer_release(void){
    isInit = 0;
}


void timer_reset(void){
    startTicks = SDL_GetTicks();
}

float timer_deltaTime(void){
    return deltaTime;
}
void timer_setTimeScale(float t){
    timeScale = t;
}
float timer_timeScale(void){
    return timeScale;
}
void timer_update(void){
    elapsedTicks = SDL_GetTicks() - startTicks;
    deltaTime = elapsedTicks * 0.001f;
}