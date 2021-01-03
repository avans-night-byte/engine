#include "EntityXMLParser.hpp"

#include <iostream>



void EntityXMLParser::createEntities(std::vector<ObjectData> &outObjectData,
                                     xsd::cxx::tree::sequence<Objects::object> &objects) {


    for (Objects::object &object : objects) {
        ObjectData data {object.name(), object.objectType()};
        for (auto &component : object.components().component()) {
         //   std::cout << component.componentName() << std::endl;
            // componentName  -> Factory
            data.xmlComponents.push_back(component._clone());
        }

        outObjectData.push_back(data);
    }
}

