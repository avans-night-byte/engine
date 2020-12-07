#include "LevelXMLParser.hpp"
#include "../Rendering/TMXLevel.hpp"

#include <iostream>
#include <map>

void LevelXMLParser::LoadLevel(std::multimap<std::string, const LevelResources::component *> &outEntities,
                               const std::map<std::string, LoadedObjectData> &loadedObjects,
                               const std::string &path) {
    std::unique_ptr<LevelResources::level> level = LevelResources::level_(path);

    for (LevelResources::object &object : level->objects().object()) {

        auto it = loadedObjects.find(std::string(object.name().c_str()));
        bool loadedObjectFound = it != loadedObjects.end();

        for (auto &component : object.components().component()) {
            std::cout << component.componentName() << std::endl;

            if (loadedObjectFound && component.componentName() == "WorldPositionComponent") {
                auto &worldPositionComponent = component.worldPositionComponent();
                auto positionF = worldPositionComponent->positionF();
                positionF.x() = it->second.position.x;
                positionF.y() = it->second.position.y;
            }

            // componentName  -> Factory
            auto pair = std::pair<std::string, const LevelResources::component *>(object.name().c_str(),
                                                                                  component._clone());

            outEntities.insert(pair);
        }
    }
}
