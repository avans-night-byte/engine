//
// Created by sascha on 11/27/20.
//

#include <include/tmxlite/Layer.hpp>
#include <include/tmxlite/TileLayer.hpp>
#include "Level.hpp"
#include "../../Game/Game.hpp"
#include "../../Game/Components/NextLevelComponent.hpp"


Level::Level(const char *tmxPath,
             const char *spritesheetPath,
             const char *spritesheetId,
             EngineRenderingAPI &engineRenderingAPI,
             PhysicsEngineAdapter &physicsEngineAdapter) : physicsEngineAdapter(physicsEngineAdapter) {
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
        } else if (layer->getType() == tmx::Layer::Type::Tile) {
            const auto tileLayer = layer->getLayerAs<tmx::TileLayer>();

            auto map_dimensions = _tmap.getTileCount();

            auto rows = map_dimensions.y;
            auto cols = map_dimensions.x;


            auto &layer_tiles = tileLayer.getTiles();


            for (auto y = 0; y < rows; ++y) {
                for (auto x = 0; x < cols; ++x) {

                    auto tile_index = x + (y * cols);
                    auto cur_gid = layer_tiles[tile_index].ID;

                    if (cur_gid == 0) {
                        continue;
                    }

                    auto texture = _tSpriteMap[cur_gid];

                    auto x_pos = x * (16 * scale);
                    auto y_pos = y * (16 * scale);

                    _tSpritesheet->select_sprite((texture.x / 16) - 1, texture.y / 16);
                    _tSpritesheet->draw_selected_sprite(x_pos, y_pos, scale);
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

                bool isSensor = false;
                ContactHandler* handler = nullptr;
                for(const auto &property : object.getProperties())
                {
                    if(property.getName() == "isSensor")
                    {
                        isSensor = true;
                    }
                    if(property.getName() == "isNextLevel")
                    {
                        // TODO: Hardcoded please create a system for this.
                        handler = new NextLevelComponent();
                    }
                }

                BodyId bodyId;
                switch(object.getShape())
                {
                    case tmx::Object::Shape::Rectangle: {
                        auto rect = object.getAABB();

                        Box2DBoxData box2DBoxData;
                        box2DBoxData.bodyType = BodyType::Static;
                        box2DBoxData.userData = handler;
                        box2DBoxData.isSensor = isSensor;
                        box2DBoxData.size = Vector2(rect.width / 2 * scale, rect.height / 2 * scale);
                        box2DBoxData.position = Vector2(
                                (object.getPosition().x * scale) + (rect.width * scale) / 2,
                                (object.getPosition().y * scale) + (rect.height * scale) / 2
                        );

                        bodyId = Game::getInstance()->getPhysicsAPI()->createStaticBody(box2DBoxData);
                        break;
                    }

                    case tmx::Object::Shape::Ellipse:
                    {
                        auto rect = object.getAABB();

                        Box2DCircleData box2DCircleData;
                        box2DCircleData.bodyType = BodyType::Static;
                        box2DCircleData.radius = (rect.width * scale) * 0.5f;
                        box2DCircleData.userData = handler;
                        box2DCircleData.isSensor = isSensor;
                        box2DCircleData.position = Vector2(
                                (object.getPosition().x * scale) + (rect.width * scale) / 2,
                                (object.getPosition().y * scale) + (rect.height * scale) / 2
                        );

                        bodyId = Game::getInstance()->getPhysicsAPI()->createStaticBody(box2DCircleData);
                        break;
                    }
                    case tmx::Object::Shape::Polygon:
                    case tmx::Object::Shape::Polyline:
                    case tmx::Object::Shape::Point: {
                        Box2DPolygonData polygonData;
                        polygonData.userData = handler;
                        polygonData.bodyType = BodyType::Static;
                        polygonData.isSensor = isSensor;
                        polygonData.position = Vector2(object.getPosition().x * scale, object.getPosition().y * scale);

                        for (const auto &point : object.getPoints()) {
                            points.push_back(Vector2(point.x * scale, point.y * scale));
                        }

                        polygonData.points = points;

                        bodyId = Game::getInstance()->getPhysicsAPI()->createStaticBody(polygonData);
                        break;
                    }
                    case tmx::Object::Shape::Text:
                        break;
                }


                bodies.push_back(bodyId);
            }
        }
    }
}

void Level::cleanup() {
    //TODO: Unload everything.
}

