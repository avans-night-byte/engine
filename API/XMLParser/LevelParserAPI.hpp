#pragma once

#include <string>
#include <memory>


#include "../../Engine/XMLParser/LevelXMLParser.hpp"

namespace Components {
    class component;
}

class TMXLevel;

struct LevelData;


class LevelParserAPI {
private:

public:
    static TMXLevel *loadLevel(std::multimap<std::string, Components::component *> &outEntities,
                               const LevelData &levelData);
};