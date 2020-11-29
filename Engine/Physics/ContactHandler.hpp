#pragma once

class ContactHandler
{
protected:
    virtual ~ContactHandler() = default;

public:
    virtual void startContact() = 0;
    virtual void endContact() = 0;
};