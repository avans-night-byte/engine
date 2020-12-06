#include "LevelXMLParser.hpp"
#include "Generated/level-resources.hxx"
#include "../Rendering/TMXLevel.hpp"

void LevelXMLParser::LoadLevel(const std::vector<LoadedObjectData> &loadedObjects, const std::string &path) {
    std::unique_ptr<LevelResources::level> level = LevelResources::level_(path);

//    for(LevelResources::object)
    level->name();
}
