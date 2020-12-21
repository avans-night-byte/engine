#pragma once

#include <string>
#include <memory>

#include "../../Engine/XMLParser/EntityXMLParser.hpp"

namespace Components {
    class component;
}

class TMXLevel;

struct LevelData;


class LevelParserAPI {
private:

public:
    static void loadEntities(std::multimap<EntityXMLParser::ObjectData, Components::component *> &outEntities,
                                  xsd::cxx::tree::sequence<Objects::object> &objects);

    static TMXLevel *loadLevel(std::multimap<EntityXMLParser::ObjectData, Components::component *> &outEntities,
                               const LevelData &levelData);
};