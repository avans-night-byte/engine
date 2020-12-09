#pragma once


#include <string>
#include <vector>
#include <map>
#include <memory>

namespace Components {
    class component;
}

struct LoadedObjectData;
class EntityObject;

class LevelXMLParser {

public:
    void loadLevel(std::multimap<std::string, Components::component *> &outEntities,
                   const std::map<std::string, LoadedObjectData> &loadedObjects, const std::string &path);
};


