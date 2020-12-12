#include "TMXLevel.hpp"

#include <include/tmxlite/TileLayer.hpp>
#include "../../Game/Game.hpp"
#include "../../Game/Components/NextLevelComponent.hpp"
#include "../Physics/PhysicsEngineAdapter.hpp"
#include "../../API/Rendering/RenderingAPI.hpp"


TMXLevel::TMXLevel(const char *tmxPath,
                   const char *spritesheetPath,
                   const char *spritesheetId,
                   const RenderingAPI &renderingAPI,
                   PhysicsEngineAdapter &physicsEngineAdapter) : physicsEngineAdapter(physicsEngineAdapter) {
    _tSpritesheet = renderingAPI.createSpriteSheet(spritesheetPath,
                                                   spritesheetId, 16, 16);
    if (!_tmap.load(tmxPath)) {
        return;
    }

    const auto &tilesets = _tmap.getTilesets();
    for (const auto &tileset : tilesets) {
        //read out tile set properties, load textures etc...

        for (const auto &tile : tileset.getTiles()) {
            _tSpriteMap[tile.ID] = Vector2(tile.imagePosition.x, tile.imagePosition.y);
        }
    }

    this->initStaticCollision(); // TODO: Remove this
}

void TMXLevel::render(RenderingAPI &renderingAPI) {
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

void TMXLevel::initObjects(std::map<std::string, LoadedObjectData> &outLoadedObjects) {
    const auto &layers = _tmap.getLayers();

    for (const auto &layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto &objects = objectLayer.getObjects();
            for (const auto &object : objects) {
                if (object.getShape() != tmx::Object::Shape::Point) {
                    continue;
                }

                const auto &position = object.getPosition();
                LoadedObjectData loadedObject = LoadedObjectData();
                loadedObject.objectName = object.getName();
                loadedObject.position = Vector2(position.x * scale, position.y * scale);

                outLoadedObjects[loadedObject.objectName] = loadedObject;
            }
        }
    }
}

void TMXLevel::initStaticCollision() {
    const auto &layers = _tmap.getLayers();

    for (const auto &layer : layers) {
        if (layer->getType() == tmx::Layer::Type::Object) {
            const auto &objectLayer = layer->getLayerAs<tmx::ObjectGroup>();
            const auto &objects = objectLayer.getObjects();
            for (const auto &object : objects) {
                std::vector<Vector2> points = std::vector<Vector2>();

                bool isSensor = false;
                ContactHandler *handler = nullptr;
                for (const auto &property : object.getProperties()) {
                    if (property.getName() == "isSensor") {
                        isSensor = true;
                    }
                }

                switch (object.getShape()) {
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

                        bodies.push_back(Game::getInstance()->getPhysicsAPI().createBody(box2DBoxData));
                        break;
                    }

                    case tmx::Object::Shape::Ellipse: {
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

                        bodies.push_back(Game::getInstance()->getPhysicsAPI().createBody(box2DCircleData));
                        break;
                    }
                    case tmx::Object::Shape::Polygon:
                    case tmx::Object::Shape::Polyline: {
                        Box2DPolygonData polygonData;
                        polygonData.userData = handler;
                        polygonData.bodyType = BodyType::Static;
                        polygonData.isSensor = isSensor;
                        polygonData.position = Vector2(object.getPosition().x * scale, object.getPosition().y * scale);

                        for (const auto &point : object.getPoints()) {
                            points.emplace_back(point.x * scale, point.y * scale);
                        }

                        polygonData.points = points;

                        bodies.push_back(Game::getInstance()->getPhysicsAPI().createBody(polygonData));
                        break;
                    }
                    case tmx::Object::Shape::Text:
                        break;
                }
            }
        }
    }
}

void TMXLevel::cleanup() {
    for (BodyId bodyId : bodies) {
        physicsEngineAdapter.destroyBody(bodyId);
    }

    bodies.clear();
}

TMXLevel::~TMXLevel() {
}

