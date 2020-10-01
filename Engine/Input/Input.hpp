#pragma once

struct Input {
    enum { KEYBOARD = 0, MOUSE = 1, CONTROLLER = 2 } device;
    int x;
    int y;
    std::string keyCode;
};
