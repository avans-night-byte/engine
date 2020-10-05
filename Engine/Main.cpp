#define SDL_MAIN_HANDLED

#include <map>
#include <SDL_render.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include <list>
#include <SDL_image.h>
#include "./Rendering/TextureManager.hpp"

#define SHAPE_SIZE 800

using namespace std;



typedef unsigned long EntityId;
typedef int PlayerId;

class Component {
protected:
    EntityId owner;
public:
    virtual void update() = 0;
    Component(EntityId id) : owner(id) {}
    virtual ~Component() {}
};

template <typename C> class System {
public:
    std::multimap<EntityId, C * > components;
};


class WorldPositionComponent : public Component {
public:
    int x, y = 0;
public:
    void update() override;
    void SetLocation(int x, int y);
    WorldPositionComponent(EntityId id) : Component(id) {}
};


void WorldPositionComponent::SetLocation(int x, int y) {
    this->x = x;
    this->y = y;

    return;
}

void WorldPositionComponent::update() {

}


class RenderComponent : public Component {
    SDL_Renderer * renderer;
    WorldPositionComponent * position;
    SDL_Texture * model;
    int r,g,b;
    char const* _texturePath;
    TextureManager* textureManager;

public:
    void update() override;
    void setColor(int red, int blue, int green) {
        r = red;
        b = blue;
        g = green;
    }
    void render() {
        textureManager->draw("sample", position->x, position->y, 859, 840, 1,0, renderer, SDL_FLIP_NONE);
    }

public:
    RenderComponent(EntityId id, WorldPositionComponent *positionComponent, SDL_Renderer *sdlRenderer, char const* texturePath)
            : Component(id), position(positionComponent) {
        renderer = sdlRenderer;
        _texturePath = texturePath;


        textureManager = TextureManager::GetInstance();
        bool textureLoad = textureManager->load(_texturePath, "sample", renderer);

        if(textureLoad){

        }
    }
};

void RenderComponent::update() {
    render();
}

class Game {
    System<Component> components;
    SDL_Renderer * sdlRenderer;
    SDL_Window *window;
    int count = 1;
    std::list<EntityId> entities;
    std::map<PlayerId, EntityId> players;

public:
    EntityId createEntity(){
        auto it = entities.begin();
        std::advance(it, entities.size());
        EntityId next = (*it) + 1;
        entities.push_back(next);

        return next;
    }
    void addComponent(EntityId id, Component* comp){
        //This would mean that for every component there is a function with different arguments.
        components.components.insert(std::pair<EntityId, Component *>(id, comp));
        return;
    }

    template <typename T>
    T* getComponent(EntityId id){
        for (auto it = components.components.begin(); it != components.components.end(); ++it) {
            if((it->first == id) && dynamic_cast<const T*>(it->second) != nullptr){
                return (T*)it->second;
            }
        }

        return nullptr;
    }

    // Get components by Entity.
    System<Component> getComponents(EntityId id){
        System<Component> returnComps;

        for (auto it = components.components.begin(); it != components.components.end(); ++it) {
            if(it->first == id){
                returnComps.components.insert(std::pair<EntityId, Component *>(id, it->second));
            }
        }

        return returnComps;
    }

    // Get components by entity/Type
    template <typename T>
    System<T> getComponents(EntityId id){
        System<Component> returnComps;

        for (auto it = components.components.begin(); it != components.components.end(); ++it) {
            T* component = dynamic_cast<const T*>(it->second);
            if(it->first == id && component != nullptr){
                returnComps.components.insert(std::pair<EntityId, T*>(id, component));
            }
        }

        return returnComps;
    }


    void init() {
        // Watch out for memory leaks.
        // No RenderComponent for invisibleObject.
        SDL_Init(SDL_INIT_VIDEO);
        window = SDL_CreateWindow(
                "SDL2Test",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                800,
                800,
                0
        );

        sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(sdlRenderer);
        SDL_RenderPresent(sdlRenderer);

        /* Initiate the entities and add their respected components */
        EntityId visibleObject = createEntity();
        addComponent(visibleObject, new WorldPositionComponent(visibleObject));

        getComponent<WorldPositionComponent>(visibleObject)->SetLocation(20,20);
        addComponent(visibleObject, new RenderComponent(visibleObject,
                                                        getComponent<WorldPositionComponent>(visibleObject), sdlRenderer, "./mario.png"));

        EntityId otherObj = createEntity();
        addComponent(otherObj, new WorldPositionComponent(otherObj));
        addComponent(otherObj, new RenderComponent(otherObj, getComponent<WorldPositionComponent>(otherObj),
                                                   sdlRenderer,"./mario.png"));


    }

    void gameLoop() {
        // Render the background.
        SDL_SetRenderDrawColor(sdlRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(sdlRenderer);


        auto * comp = getComponent<WorldPositionComponent>(1);
        comp->SetLocation(20 + (count)  , 200);

        auto * comp1 = getComponent<WorldPositionComponent>(2);
        comp1->SetLocation(200 + (count)  , 400);

        // Move all position items to 100, 100 and render them after that.
        auto it = components.components.begin();
        for (it = components.components.begin(); it != components.components.end(); ++it) {
            it->second->update();
        }

        count++;
        // Render the created backbuffer.
        SDL_RenderPresent(sdlRenderer);
    }


    void endGame(){
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};



int main(int argc, char *argv[])
{
    // Throw away game class
    Game g = Game();

    // Init rendering
    g.init();

    // Sample gameloop.
    bool gameEnded = false;
    SDL_Event event;

    bool setColor = false;

    WorldPositionComponent * worldComp = g.getComponent<WorldPositionComponent>(1);
    RenderComponent * comp = g.getComponent<RenderComponent>(1);

    while(!gameEnded){
        // If close is pressed on the window, close the game.
        if(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                gameEnded = true;
            }
        }

        // Call the engine gameloop.
        g.gameLoop();

        std::cout << worldComp->x << endl;
    }

    g.endGame();

    return 0;
}