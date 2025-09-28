#ifndef CoreManager_h
#define CoreManager_h

/*----------------------------------------------------------------|
--------------------- Module Description -------------------------|
class to handle all function calls to the Simulation class
-----------------------------------------------------------------*/

#include "Simulation.hpp"
#include "framerate_timer.hpp"

namespace pce {

class CoreManager {
    Simulation simulation_;
    int fps_ = 60;
    int frameDelay_ = 1000/fps_;
    int frameStart_ = 0;
    uint32_t frameTime_ = 0;
    framerate_timer framerate_timer_;
public:
    CoreManager( const char* title = "PineconeEngine"
               , int screen_x = 1000
               , int screen_y = 672);
    ~CoreManager();

    void doCorePreUpdate();
    void doCorePostUpdate();
    void updateFramerateTimer();
    void screenParameters(int x, int y);
    bool running() const;
    SDL_Renderer* renderer();

    /* static items */
    int SCREEN_X;
    int SCREEN_Y;
    double time_;

    bool USE_TIMER = true;
    std::vector<SDL_Event>& frameEvents();
};


}




#endif /* CoreManager_h */
