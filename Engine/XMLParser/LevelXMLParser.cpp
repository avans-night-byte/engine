#include "LevelXMLParser.hpp"
#include "../Rendering/TMXLevel.hpp"
#include "Generated/components.hxx"
#include "Generated/level-resources.hxx"
#include "Generated/objects.hxx"

#include <iostream>
#include <map>

void LevelXMLParser::loadLevel(std::multimap<std::string, Components::component *> &outEntities,
                               const std::map<std::string, LoadedObjectData> &loadedObjects,
                               const std::string &path) {
    std::unique_ptr<LevelResources::level> level = LevelResources::level_(path);
    std::unique_ptr<Objects::objectList> objectList = Objects::objectList_(path);

    for (Objects::object &object : level->object()) {
        auto it = loadedObjects.find(std::string(object.name().c_str()));
        bool objectPersistsInTMX = it != loadedObjects.end();

        for (auto &component : object.components().component()) {
            std::cout << component.componentName() << std::endl;

            if (objectPersistsInTMX && component.componentName() == "TransformComponent") {
                auto &worldPositionComponent = component.transformComponent();
                auto &positionF = worldPositionComponent->position();
                positionF.x() = it->second.position.x;
                positionF.y() = it->second.position.y;
            }


            // componentName  -> Factory
            auto pair = std::pair<std::string, Components::component *>(object.name().c_str(), component._clone());

            outEntities.insert(pair);
        }
    }
}
