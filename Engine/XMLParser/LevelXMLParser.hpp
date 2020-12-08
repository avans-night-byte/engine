#pragma once


#include <string>
#include <vector>
#include <map>
#include <memory>
#include <Generated/level-resources.hxx>


struct LoadedObjectData;
class EntityObject;

class LevelXMLParser {

public:
    void LoadLevel(std::multimap<std::string, const LevelResources::component *> &outEntities,
                   const std::map<std::string, LoadedObjectData> &loadedObjects, const std::string &path);
};


