#pragma once

#include "iostream"
#include "ContactHandler.hpp"

#include <box2d.h>

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact) override {
        if (auto *bodyUserData = (ContactHandler *) (contact->GetFixtureA()->GetBody()->GetUserData().pointer)) {
            bodyUserData->startContact(contact);
        }

        if (auto *bodyUserData = (ContactHandler *) contact->GetFixtureB()->GetBody()->GetUserData().pointer) {
            bodyUserData->startContact(contact);
        }
    }

    void EndContact(b2Contact *contact) override {
        if (auto *bodyUserData = (ContactHandler *) contact->GetFixtureA()->GetBody()->GetUserData().pointer) {
            bodyUserData->endContact(contact);
        }

        if (auto *bodyUserData = (ContactHandler *) contact->GetFixtureB()->GetBody()->GetUserData().pointer) {
            bodyUserData->endContact(contact);
        }
    }
};