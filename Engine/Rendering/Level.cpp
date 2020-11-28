//
// Created by sascha on 11/27/20.
//

#include <include/tmxlite/Layer.hpp>
#include <include/tmxlite/TileLayer.hpp>
#include <iostream>
#include "Level.hpp"
#include "../../API/Rendering/EngineRenderingAPI.hpp"
#include "../../Game/Game.hpp"

Level::Level(const char * tmxPath, const char* spritesheetPath, const char*  spritesheetId, EngineRenderingAPI& engineRenderingAPI) {
    _tSpritesheet = engineRenderingAPI.createSpriteSheet(spritesheetPath,
                                                         spritesheetId, 40, 40, 16, 16);
    if (_tmap.load(tmxPath)) {
        const auto &tilesets = _tmap.getTilesets();
        for (const auto &tileset : tilesets) {
            //read out tile set properties, load textures etc...

            for (const auto &tile : tileset.getTiles()) {
                _tSpriteMap[tile.ID] = Vector2(tile.imagePosition.x, tile.imagePosition.y);
            }
        }

        this->initCollision();
    }
}

void Level::initialize() {

}

void Level::render(EngineRenderingAPI& engineRenderingApi) {
    const auto &layers = _tmap.getLayers();

    for (const auto &layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
//            const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
//            const auto &objects = objectLayer.getObjects();
//            for (const auto &object : objects) {
//                for (const auto &point : object.getPoints()) {
//                    std::cout << point.x << " " << point.y << std::endl;
//                }
//            }
        } else if (layer->getType() == tmx::Layer::Type::Tile) {
            const auto tileLayer = layer->getLayerAs<tmx::TileLayer>();
            //read out tile layer properties etc...

//            for (const auto &chunk : tileLayer.getChunks()) {
//                std::cout << chunk.position.x << " " << chunk.position.y << std::endl;
//
//                for (const auto &tile : chunk.tiles) {
//                //    std::cout << tile.ID << " " << tile.flipFlags << std::endl;
//                }
//
//            }

            auto map_dimensions = _tmap.getTileCount();
            auto rows = map_dimensions.y;
            auto cols = map_dimensions.x;


            auto &layer_tiles = tileLayer.getTiles();


            for (auto y = 0; y < rows; y++) {
                for (auto x = 0; x < cols; x++) {

                    auto tile_index = x + (y * rows);
                    auto cur_gid = layer_tiles[tile_index].ID;

                    if (cur_gid == 0) {
                        continue;
                    }

                    auto texture = _tSpriteMap[cur_gid];

                    auto x_pos = x * 16;
                    auto y_pos = y * 16;

                    _tSpritesheet->select_sprite((texture.x / 16) - 1, texture.y / 16);
                    _tSpritesheet->draw_selected_sprite(x_pos, y_pos);

                }
            }
        }
    }
}


void Level::initCollision(){
    const auto &layers = _tmap.getLayers();

    for (const auto &layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto &objects = objectLayer.getObjects();
            for (const auto &object : objects) {
                std::vector<Vector2> points = std::vector<Vector2>();



                for (const auto &point : object.getPoints()) {
                    points.push_back(Vector2(point.x, point.y));
                }


                if(points.empty()){
                    // Rectangle
                    auto rect = object.getAABB();
                    Game::getInstance()->getPhysicsAPI()->createStaticBody(BodyType::Static, Vector2(object.getPosition().x, object.getPosition().y), Vector2(rect.width/2, rect.height/2));
                    continue;
                }


                Vector2 pos = Vector2(object.getPosition().x, object.getPosition().y);
                Game::getInstance()->getPhysicsAPI()->createStaticBody(BodyType::Static, pos , points);
            }
        }
    }
}

void Level::cleanup() {
    //TODO: Unload everything.
}

