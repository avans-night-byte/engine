#pragma once

#include <string>

class WindowAPI
{
public:
    virtual void initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) const = 0;
    virtual void closeWindow() const = 0;

    /*Cheat Window*/
    virtual void renderCheatMenu(bool &cheatMode) const = 0;
    virtual void clearCheatMenu() const = 0;
    virtual bool showCheckBox(const std::string &label, bool *value) const = 0;
    virtual bool showInputFloat(const std::string &label, float *value) const = 0;
    virtual bool showInputInt(const std::string &label, int *value) const = 0;
    virtual bool showInputText(const std::string &label, char *value, int bufferSize) const = 0;
    virtual bool button(const std::string &label) const = 0;
};
