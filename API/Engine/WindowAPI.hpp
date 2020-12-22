#pragma once

class WindowAPI
{
public:
    virtual void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const = 0;
    virtual void closeWindow() const = 0;
};