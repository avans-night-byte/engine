//
// Created by Martijn on 22/11/2020.
//

#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>
#include <iostream>
#include "./Level1.hpp"
#include <cmath>

Spritesheet *overworld;
std::map<int, Vector2> id_map;
tmx::Map map;

int loadLevel(EngineRenderingAPI *engineRenderingAPI) {
    overworld = engineRenderingAPI->createSpriteSheet("../../Resources/Sprites/Overworld.png",
                                                      "nigga_overworld", 40, 40, 16, 16);

    std::cout << "Load level started" << std::endl;
    if (map.load("C:\\Users\\Martijn\\Documents\\Avans\\Minor\\engine\\Resources\\example.tmx")) {

        const auto &tilesets = map.getTilesets();
        for (const auto &tileset : tilesets) {
            //read out tile set properties, load textures etc...

            for (const auto &tile : tileset.getTiles()) {
                id_map[tile.ID] = Vector2(tile.imagePosition.x, tile.imagePosition.y);

            }
        }
    }

    return 0;
}

void render(EngineRenderingAPI *engineRenderingAPI) {



    const auto &layers = map.getLayers();

    for (const auto &layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto &objects = objectLayer.getObjects();
            for (const auto &object : objects) {
//                    for (const auto &point : object.getPoints()) {
//                        std::cout << point.x << " " << point.y << std::endl;
//                    }

            }
        } else if (layer->getType() == tmx::Layer::Type::Tile) {
            const auto &tileLayer = layer->getLayerAs<tmx::TileLayer>();
            //read out tile layer properties etc...

//            for (const auto &chunk : tileLayer.getChunks()) {
//                std::cout << chunk.position.x << " " << chunk.position.y << std::endl;
//
//                for (const auto &tile : chunk.tiles) {
//                //    std::cout << tile.ID << " " << tile.flipFlags << std::endl;
//                }
//
//            }

            auto map_dimensions = map.getTileCount();
            auto rows = map_dimensions.y;
            auto cols = map_dimensions.x;


            auto& layer_tiles = tileLayer.getTiles();


            for (auto y = 0; y < rows; y++) {
                for (auto x = 0; x < cols; x++) {

                    auto tile_index = x + (y * rows);
                    auto cur_gid = layer_tiles[tile_index].ID;

                    if (cur_gid == 0) {
                        continue;
                    }

                    auto texture = id_map[cur_gid];

                    auto x_pos = x * 32;
                    auto y_pos = y * 32;

                    overworld->select_sprite((texture.x / 16) - 1, texture.y / 16);
                    overworld->draw_selected_sprite(x_pos, y_pos);

                }
            }

//            for (int i = 0; i < h; ++i) {
//                for (int j = 0; j < w; ++j) {
//                    tmx::TileLayer::Tile tile = tileLayer.getTiles()[i + (j * h)];
//                    Vector2 texture = id_map[tile.ID];
//
//                    overworld->select_sprite(texture.x, texture.y);
//                    overworld->draw_selected_sprite(16 * i, 16 * j);
//                }
//            }

//            for (int i = 0; i < tileLayer.getTiles().size(); ++i) {
//
//
//                overworld->select_sprite(texture.x, texture.y);
//                overworld->draw_selected_sprite(16, 16 * (h / i));
//            }




        }
    }

}