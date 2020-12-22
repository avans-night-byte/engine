#pragma once

#include "iostream"
#include "ContactHandler.hpp"
#include "b2_user_settings.h"

#include <box2d.h>

class ContactListener : public b2ContactListener {
    void BeginContact(b2Contact *contact) override {
        if (auto *bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData().contactHandler) {
            bodyUserData->startContact(contact, true);
        }

        if (auto *bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData().contactHandler) {
            bodyUserData->startContact(contact, false);
        }
    }

    void EndContact(b2Contact *contact) override {
        if (auto *bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData().contactHandler) {
            bodyUserData->endContact(contact, true);
        }

        if (auto *bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData().contactHandler) {
            bodyUserData->endContact(contact, false);
        }
    }
};