#pragma once

class b2Contact;

class ContactHandler {
public:
    virtual void startContact(b2Contact *contact, bool isA) = 0;

    virtual void endContact(b2Contact *contact, bool isA) = 0;
};