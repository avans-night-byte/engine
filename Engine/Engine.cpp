#define IMGUI_IMPL_OPENGL_LOADER_GLAD

#include <iostream>
#include "./Engine.hpp"
#include "Rendering/TextureManager.hpp"


// Dependencies
#include "./Rendering/Adapter/SDLRenderingAdapter.hpp"

// Dear ImGui
#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <imgui_impl_opengl3.h>

// SDL
#include <SDL.h>
#include <glad/glad.h>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_ttf.h>


// Variables
SDL_Window *window = nullptr;


/**
 * Initialize the game window
 * 
 * Stores a SDL_Window pointer in the Engine class.
 * 
 * @param SCREEN_WIDTH The width of the window.
 * @param SCREEN_HEIGHT The height of the window.
 **/
void Engine::initWindow(int SCREEN_WIDTH, int SCREEN_HEIGHT) {

    SDL_Surface *surface = nullptr;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER | SDL_INIT_AUDIO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        // set OpenGL attributes
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        SDL_GL_SetAttribute(
                SDL_GL_CONTEXT_PROFILE_MASK,
                SDL_GL_CONTEXT_PROFILE_CORE
        );

        SDL_DisplayMode current;
        SDL_GetCurrentDisplayMode(0, &current);
        // Create window
        window = SDL_CreateWindow("NightByte", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n",
                   SDL_GetError());
        } else {
            SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            this->_renderingAdapter = std::make_unique<SDLRenderingAdapter>(renderer);
            TTF_Init();

            std::string glsl_version;
#ifdef __APPLE__
            // GL 3.2 Core + GLSL 150
    glsl_version = "#version 150";
    SDL_GL_SetAttribute( // required on Mac OS
        SDL_GL_CONTEXT_FLAGS,
        SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG
        );
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
#elif __linux__
            // GL 3.2 Core + GLSL 150
    glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
#elif _WIN32
            // GL 3.0 + GLSL 130
            glsl_version = "#version 130";
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#endif

            SDL_GLContext gl_context = SDL_GL_CreateContext(window);
            SDL_GL_MakeCurrent(window, gl_context);

            // enable VSync
            SDL_GL_SetSwapInterval(1);

            // setup Dear ImGui context
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO &io = ImGui::GetIO();
            (void) io;

            // setup Dear ImGui style
            ImGui::StyleColorsDark();

            // setup platform/renderer bindings
            ImGui_ImplSDL2_InitForOpenGL(window, gl_context);

            if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
                std::cerr << "[ERROR] Couldn't initialize glad" << std::endl;
            } else {
                std::cout << "[INFO] glad initialized\n";
            }

            ImGui_ImplOpenGL3_Init(glsl_version.c_str());
        }
    }
}

EngineRenderingAdapter &Engine::getRenderingAdapter() {
    return *_renderingAdapter;
}

/**
 * Close the game window
 * 
 * Clears the SDL_Window pointer in the Engine class and calls SDL_DestroyWindow & SDL_Quit.
 **/
void Engine::closeWindow() {
    _renderingAdapter->deleteRenderer();
    SDL_DestroyWindow(window);
    SDL_Quit();
}


// Singleton
Engine *Engine::instance_{nullptr};
std::mutex Engine::mutex_;


Engine *Engine::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);

    if (instance_ == nullptr) {
        instance_ = new Engine();
    }

    return instance_;
}


void Engine::renderImGui(bool &cheatMode) {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);
    ImGui::NewFrame();


    ImGui::Begin("Nightbyte CheatMode", &cheatMode, ImGuiWindowFlags_MenuBar);


}



void Engine::clearImGui() {
    ImGui::End();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ImGui::Render();
    glViewport(0, 0, (int) ImGui::GetIO().DisplaySize.x, (int) ImGui::GetIO().DisplaySize.y);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

bool Engine::ShowCheckBox(const std::string &label, bool *value) {
    return ImGui::Checkbox(label.c_str(), value);
}
