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
    void LoadLevel(std::multimap<std::string, const Components::component *> &outEntities,
                   const std::map<std::string, LoadedObjectData> &loadedObjects, const std::string &path);
};


