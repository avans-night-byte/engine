#pragma once

struct Vector2
{
public:
    float x;
    float y;

    Vector2(float x, float y) : x(x), y(y)
    {

    }

    Vector2() :x(0), y(0) {

    }

    Vector2 operator+(const Vector2& other) const {
        return Vector2(other.x + x, other.y + y);
    }

    Vector2 operator-(const Vector2& other) const {
        return Vector2(other.x - x, other.y - y);
    }

    Vector2 operator*(float scale) const {
        return Vector2(x * scale, y * scale);
    }
};