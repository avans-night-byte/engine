#include "LevelParser.hpp"
#include "Generated/level-resources.hxx"


void LevelParser::LoadLevel(const std::string &path) {
    std::unique_ptr<LevelResources::level> level = LevelResources::level_(path);

    level->name();
}
