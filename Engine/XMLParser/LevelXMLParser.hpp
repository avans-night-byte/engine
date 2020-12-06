#pragma once


#include <string>
#include <vector>

struct LoadedObjectData;

class LevelXMLParser {

public:
    void LoadLevel(const std::vector<LoadedObjectData>& loadedObjects, const std::string& path);
};


