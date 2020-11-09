#include "mathHelper.h"

inline Vector2 Vector2_0(void)
{
    Vector2 vec = {0.0f, 0.0f};
    return vec;
}
inline Vector2 Vector2_(float const x, float const y)
{
    Vector2 vec = {x, y};
    return vec;
}
inline float Vector2_MagnitudeSqr(Vector2 const self)
{
    return self.x * self.x + self.y * self.y;
}
inline float Vector2_Magnitude(Vector2 const self)
{
    return sqrtf(self.x * self.x + self.y * self.y);
}

inline Vector2 Vector2_Normalized(Vector2 const self)
{
    float mag = Vector2_Magnitude(self);
    return Vector2_(self.x / mag, self.y / mag);
}
inline Vector2 Vector2_Plus_Equal(Vector2 self, Vector2 const that)
{
    self.x += that.x;
    self.y += that.y;
    return self;
}
inline Vector2 Vector2_Minus_Equal(Vector2 self, Vector2 const that)
{
    self.x -= that.x;
    self.y -= that.y;
    return self;
}
inline Vector2 Vector2_Minus_Unary(Vector2 const self)
{
    return Vector2_(-self.x, -self.y);
}

inline Vector2 Vector2_Plus(Vector2 const r, Vector2 const l)
{
    return Vector2_(r.x + l.x, r.y + l.y);
}
inline Vector2 Vector2_Minus(Vector2 const r, Vector2 const l)
{
    return Vector2_(r.x - l.x, r.y - l.y);
}

inline Vector2 Vector2_Times_f(Vector2 const r, float const l)
{
    return Vector2_(r.x * l, r.y * l);
}

inline Vector2 Vector2_Lerp(Vector2 const start, Vector2 const end, float const time)
{

    if (time <= 0.0f)
        return start;

    if (time >= 1.0f)
        return end;

    Vector2 diff = Vector2_Minus(end, start);

    return Vector2_Plus(start, Vector2_Times_f(Vector2_Normalized(diff), Vector2_Magnitude(diff) * time));
}
inline Vector2 Vector2_Rotate(Vector2 const vec, float const angle)
{

    float radAngle = (float)(angle * DEG_TO_RAD);

    return Vector2_((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}