#pragma once

#include <string>
#include <memory>


#include "../../Engine/XMLParser/LevelXMLParser.hpp"

class TMXLevel;

struct TMXLevelData;


class LevelParserAPI {
private:
    std::unique_ptr<LevelXMLParser> levelXMLParser;
    std::unique_ptr<TMXLevel> levelLoader;

public:
    void LoadLevel(const TMXLevelData& levelData, const std::string &resourcePath);
};