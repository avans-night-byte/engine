#include "EntityXMLParser.hpp"

#include <iostream>
#include <map>

void EntityXMLParser::createEntities(std::multimap<std::string, Components::component *> &outEntities,
                                     xsd::cxx::tree::sequence<Objects::object> &objects) {

    for (Objects::object &object : objects) {
        for (auto &component : object.components().component()) {
            std::cout << component.componentName() << std::endl;

            // componentName  -> Factory
            auto pair = std::pair<std::string, Components::component *>(object.name().c_str(), component._clone());

            outEntities.insert(pair);
        }
    }
}