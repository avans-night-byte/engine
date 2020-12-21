#include "EntityXMLParser.hpp"

#include <iostream>
#include <map>
#include <utility>



void EntityXMLParser::createEntities(std::multimap<ObjectData, Components::component *> &outEntities,
                                     xsd::cxx::tree::sequence<Objects::object> &objects) {

    for (Objects::object &object : objects) {
        ObjectData data {object.name(), object.objectType()};
        for (auto &component : object.components().component()) {
            std::cout << component.componentName() << std::endl;

            // componentName  -> Factory
            auto pair = std::pair<ObjectData, Components::component *>(data, component._clone());

            outEntities.insert(pair);
        }
    }
}

