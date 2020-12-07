#pragma once

#include <string>
#include <memory>


#include "../../Engine/XMLParser/LevelXMLParser.hpp"

class TMXLevel;

struct TMXLevelData;


class LevelParserAPI {
private:

public:
    static void loadLevel(std::multimap<std::string, const LevelResources::component *> &outEntities,
                   const TMXLevelData &levelData,
                   const std::string &resourcePath);
};