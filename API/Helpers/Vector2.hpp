#pragma once

/**
 * Helper class that holds a x and y float value, useful for 2d positions and forces.
 */
struct Vector2
{
public:
    float x = 0;
    float y = 0;


    Vector2(){

    }


    Vector2(float x, float y) : x(x), y(y)
    {

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

    Vector2 operator*(const Vector2& other) {
        return Vector2(x * other.x, y * other.y);
    }

    bool operator==(const Vector2& other) {
        return x == other.x && y == other.y;
    }

    bool operator<(const Vector2& other) const
    {
        return (x < other.x) && (y < other.y);
    }
};


