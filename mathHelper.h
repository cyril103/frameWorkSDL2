#ifndef _MATHHELPER_H
#define _MATHHELPER_H

#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f
#define RAD_TO_DEG 180.0f / PI

typedef struct Vector2
{
    float x;
    float y;
} Vector2;

Vector2 Vector2_(float const x, const float y);
Vector2 Vector2_0(void);
float Vector2_MagnitudeSqr(Vector2 const self);
float Vector2_Magnitude(Vector2 const self);
Vector2 Vector2_Normalized(Vector2 const self);
Vector2 Vector2_Plus_Equal(Vector2 self, Vector2 const that);
Vector2 Vector2_Minus_Equal(Vector2 self, Vector2 const that);
Vector2 Vector2_Minus_Unary(Vector2 const self);
Vector2 Vector2_Plus(Vector2 const r, Vector2 const l);
Vector2 Vector2_Minus(Vector2 const r, Vector2 const l);
Vector2 Vector2_Times_f(Vector2 const r, float const l);
Vector2 Vector2_Lerp(Vector2 const start, Vector2 const end, float const time);
Vector2 Vector2_Rotate(Vector2 const vec, float const angle);

#endif
