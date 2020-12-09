#pragma once

class ContactHandler
{
public:
    virtual void startContact() = 0;
    virtual void endContact() = 0;
};