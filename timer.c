#include "timer.h"

static Timer *s_instance = NULL;

static Timer *Timer_new(void);

static Timer *Timer_new(void)
{
    Timer model = {
        .reset = timer_reset,
        .deltaTime = timer_deltaTime,
        .setTimeScale = timer_setTimeScale,
        .timeScale = timer_timeScale,
        .update = timer_update,
    };

    s_instance = memory_Alloc(sizeof(Timer));
    memcpy(s_instance, &model, sizeof(Timer));
    s_instance->reset();
    s_instance->mTimeScale = 1.0f;
    return s_instance;
}

Timer *timer_instance(void)
{
    if (s_instance == NULL)
        s_instance = Timer_new();

    return s_instance;
}

void timer_release(void)
{
    memory_Free(s_instance, sizeof(Timer));
    s_instance = NULL;
}

void timer_reset(void)
{
    s_instance->mStartTicks = SDL_GetTicks();
    s_instance->mElapsedTicks = 0;
    s_instance->mDelataTime = 0.0f;
}

float timer_deltaTime(void)
{
    return s_instance->mDelataTime;
}
void timer_setTimeScale(float t)
{
    s_instance->mTimeScale = t;
}
float timer_timeScale(void)
{
    return s_instance->mTimeScale;
}
void timer_update(void)
{
    s_instance->mElapsedTicks = SDL_GetTicks() - s_instance->mStartTicks;
    s_instance->mDelataTime = s_instance->mElapsedTicks * 0.001f;
}