#include "Math.h"
Vector2 Vect2::operator+(const Vector2& other) const {
    return { x + other.x, y + other.y };
}