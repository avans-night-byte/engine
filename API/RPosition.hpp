#pragma once

// TODO: Create a helper project for the data classes.
struct RPosition {
    RPosition(const float &x, const float &y) : X(x), Y(y) {

    }

    const float &X;
    const float &Y;
};