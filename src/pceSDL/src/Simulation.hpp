#ifndef Simulation_h
#define Simulation_h

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
class for initializing SDL and managing the SDL event loop
-----------------------------------------------------------------*/
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace pce {

class Simulation {
public:
    void init(const char* title
          , int width=1000
          , int height=672
          , int xpos=SDL_WINDOWPOS_CENTERED
          , int ypos=SDL_WINDOWPOS_CENTERED
          , bool fullscreen=false);

    void handleEvents();
    void clearFrameEvents();

    void render();
    void clearRenderer();
    void clean();
    bool running() { return isRunning; }

    bool isRunning = true;
    SDL_Renderer* renderer = nullptr;
    SDL_Event event;
    std::vector<SDL_Event> frame_events;
private:
    SDL_Window* window_ = nullptr;
};

}





#endif /* Simulation_h */
