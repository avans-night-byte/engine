#include "TMXLevel.hpp"

#include <include/tmxlite/TileLayer.hpp>
#include "../../Game/Game.hpp"
#include "../../Game/Components/NextLevelComponent.hpp"
#include "../../Game/Components/TransformComponent.hpp"
#include "../Astar.hpp"

#include <box2d.h>
#include <map>
#include <future>

TMXLevel::TMXLevel(const char *tmxPath,
                   const char *spritesheetPath,
                   const char *spritesheetId,
                   const RenderingAPI &renderingAPI,
                   PhysicsEngineAdapter &physicsEngineAdapter) : physicsEngineAdapter(physicsEngineAdapter) {
    _tSpritesheet = renderingAPI.loadSpriteSheet(spritesheetPath,
                                                 spritesheetId, 16, 16, 0, 0);
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

                    _tSpritesheet->selectSprite((texture.x / 16) - 1, texture.y / 16);
                    _tSpritesheet->drawSelectedSprite(x_pos, y_pos, scale);
                }
            }
        }
    }
}

struct LoadedObjectData {
    std::string objectName;
    Vector2 position;
};

void TMXLevel::getObjectPositions(std::vector<EntityXMLParser::ObjectData> &outEntities) {
    const auto &layers = _tmap.getLayers();
    auto loadedObjects = std::map<std::string, LoadedObjectData>();

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

                loadedObjects[loadedObject.objectName] = loadedObject;
            }
        }
    }

    for (auto &object : loadedObjects) {
        for (auto &xmlEntity : outEntities) {
            if (xmlEntity.name != object.first)
                continue;

            bool transformFound = false;

            for (auto comp : xmlEntity.xmlComponents) {
                if (!comp->transformComponent().present())
                    continue;

                auto &worldPositionComponent = comp->transformComponent();
                auto &positionF = worldPositionComponent->position();
                positionF.x() = object.second.position.x;
                positionF.y() = object.second.position.y;

                transformFound = true;
                break;
            }

            if (!transformFound) {
                throw std::runtime_error(
                        "Object: '" + object.first + "' couldn't be attached to a resource object");
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
                        box2DBoxData.contactHandler = handler;
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
                        box2DCircleData.contactHandler = handler;
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
                        polygonData.contactHandler = handler;
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

TMXLevel::~TMXLevel() = default;

class MyQueryCallback : public b2QueryCallback {
private:
    bool _hasCollider = false;
public:
    std::map<Vector2, int> positions;
    std::vector<b2Fixture*> fixtures;

    bool ReportFixture(b2Fixture* fixture) {
        fixtures.push_back(fixture);
        return true;
    }
};

/**
 * @param weights
 */
std::vector< std::vector<int>> TMXLevel::GetGrid() const {
    /**
     * Create a upper and lower bounawdds. Basicly the bounds of the tile and query for objects.
     * When a static object is within this bound, mark this square as an obstruction.
     */
    const auto &world = Game::getInstance()->getPhysicsAPI().getWorld();
    std::map<Vector2, int> testPositions;
    std::vector< std::vector<int> > weights(30, std::vector<int>(30, 0));

    for(int y = 0; y < 30; y++) {

        for(int x = 0; x < 30; x++){
            b2AABB aabb;

            float xPos = x * (16 * scale);
            float yPos = y * (16 * scale);

            float upperX = xPos + (16 * scale);
            float upperY = yPos + (16 * scale);
            auto queryCallback = MyQueryCallback();

            aabb.lowerBound = b2Vec2{xPos, yPos};
            aabb.upperBound = b2Vec2{upperX, upperY};

            world.QueryAABB(&queryCallback, aabb);

            for(const auto* fixture : queryCallback.fixtures){
                auto bodyPos = fixture->GetBody()->GetPosition();
                auto pos = Vector2{bodyPos.x, bodyPos.y};

                if(fixture->GetBody()->GetType() == b2_staticBody){
                    weights[y][x] = 1;
                    break;
                }


                if(fixture->IsSensor()){
                    weights[y][x] = 0;
                }

                if(pos == Game::getInstance()->getCharacter()->getTransform()->getPosition()){
                    weights[y][x] = 0;
                }

                if(fixture->GetBody()->GetType() == b2_dynamicBody){
                    weights[y][x] = 2;
                }
            }
        }
    }

    return weights;
}

