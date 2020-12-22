#pragma once


#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Generated/objects.hxx>

namespace Components {
    class component;
}


class EntityObject;

class EntityXMLParser {

public:
    struct ObjectData{
    public:
        std::string name;
        std::string type;

        std::vector<Components::component*> xmlComponents;

        ObjectData(std::string name, std::string type) : name(std::move(name)), type(std::move(type)) {

        }
    };

    static void createEntities(std::vector<ObjectData> &outObjectData,
                        xsd::cxx::tree::sequence<Objects::object> &objects);
};


