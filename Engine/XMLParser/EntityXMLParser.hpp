#pragma once


#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Generated/objects.hxx>

namespace Components {
    class component;
}

struct LoadedObjectData;

class EntityObject;

class EntityXMLParser {

public:
    struct ObjectData{
    public:
        std::string name;
        std::string type;

        ObjectData(std::string name, std::string type) : name(std::move(name)), type(std::move(type)) {}

        bool operator==(const ObjectData &other) const{
            return name == other.name;
        }

        bool operator==(const std::string &other) const{
            return name == other;
        }

        bool operator<(const ObjectData &other) const{
            int result = name.compare(other.name);
            if(result < 0) return true;
            return false;
        }
    };

    static void createEntities(std::multimap<ObjectData, Components::component *> &outEntities,
                        xsd::cxx::tree::sequence<Objects::object> &objects);
};


