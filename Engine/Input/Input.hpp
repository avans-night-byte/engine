#pragma once

struct InputAction
{
    std::string code;
    std::string action;
};

struct Input
{
    enum
    {
        KEYBOARD = 0,
        MOUSE = 1,
        CONTROLLER = 2
    } device;
    int x;
    int y;
    InputAction keyMap;
};
