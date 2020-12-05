#pragma once

#include "memory"
#include "../../Engine/XMLParser/LevelParser.hpp"


using namespace std;

class LevelParserAPI {
private:
    unique_ptr<LevelParser> levelParser;

public:
    void LoadLevel(const string& path) {
        levelParser = make_unique<LevelParser>();
        levelParser->LoadLevel(path);
    }
};