#ifndef CoreManager_cpp
#define CoreManager_cpp

#include "CoreManager.hpp"

//#include <string>
#include <pceLogger/pceLogger.hpp>

namespace pce {
namespace {
const std::string log_name = "core_mgr";
}

//int pce::CoreManager::SCREEN_X = 1000;
//int pce::CoreManager::SCREEN_Y = 672;
//double pce::CoreManager::time_ = 0.0;


CoreManager::CoreManager(const char* title, int screen_x, int screen_y)
{
    LOG_DEBUG(log_name) << "ctor";
    screenParameters(screen_x, screen_y);
    simulation_.init(title, screen_x, screen_y);
}


CoreManager::~CoreManager()
{
    simulation_.clean();
}


void CoreManager::doCorePreUpdate()
{
    //LOG_DEBUG(log_name) << "doCorePreUpdate";
    frameStart_ = SDL_GetTicks();       
    simulation_.handleEvents();
    simulation_.clearRenderer();
    if (USE_TIMER)
        updateFramerateTimer();
    pce::CoreManager::time_ = static_cast<double>(frameStart_) / 1000.0;
}


void CoreManager::updateFramerateTimer()
{
    framerate_timer_.update(static_cast<int>(frameStart_/1000)); 
}


void CoreManager::doCorePostUpdate()
{
    //LOG_DEBUG(log_name) << "doCorePostUpdate";
    simulation_.render();
    simulation_.clearFrameEvents();

    frameTime_ = SDL_GetTicks() - frameStart_;
    if (frameDelay_ > frameTime_)
        SDL_Delay(frameDelay_ - frameTime_);
}
  

void CoreManager::screenParameters(int x, int y)
{
    SCREEN_X = x;
    SCREEN_Y = y;
}


bool CoreManager::running() const { return simulation_.isRunning; }


SDL_Renderer* CoreManager::renderer()
{
    return simulation_.renderer;
}

std::vector<SDL_Event>& CoreManager::frameEvents()
{
    return simulation_.frame_events;
}

} /* namespace pce */





#endif /* CoreManager_cpp */
