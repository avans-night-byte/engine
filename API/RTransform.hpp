#pragma once

// TODO: Create a helper project for the data classes.
struct RTransform {
    RTransform(const float &x, const float &y, float rotation) : X(x), Y(y), rotation(rotation) {

    }

    const float &X;
    const float &Y;
    float rotation;
};