//
// Created by sasch on 28/09/2020.
//

#ifndef SDL2TEST_ENTITY_HPP
#include "./Components/Component.hpp"
#define SDL2TEST_ENTITY_HPP


class Entity {
private:
    typedef unsigned long EntityId;
public:
    void update();
    Component* getComponent();
};


#endif //SDL2TEST_ENTITY_HPP
