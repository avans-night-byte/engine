#pragma once

#include "iostream"
#include <box2d.h>
#include "ContactHandler.hpp"

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