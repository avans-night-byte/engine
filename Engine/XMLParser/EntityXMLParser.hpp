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
    static void createEntities(std::multimap<std::string, Components::component *> &outEntities,
                        xsd::cxx::tree::sequence<Objects::object> &objects);
};


