#include "LevelParser.hpp"

void LevelParser::LoadLevel(string& path) {
    unique_ptr<XLevel> level = XLevel_(path);


}
