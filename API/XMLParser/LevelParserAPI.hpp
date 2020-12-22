#pragma once

#include "../../Engine/XMLParser/EntityXMLParser.hpp"

#include <string>
#include <memory>


namespace Components {
    class component;
}

class TMXLevel;

struct LevelData;


class LevelParserAPI {
private:

public:
    static void loadEntities(std::vector<EntityXMLParser::ObjectData> &outEntities,
                                  xsd::cxx::tree::sequence<Objects::object> &objects);

    static TMXLevel *loadLevel(std::vector<EntityXMLParser::ObjectData> &outEntities,
                               const LevelData &levelData);
};