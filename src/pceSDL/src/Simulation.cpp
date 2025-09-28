#ifndef Simulation_cpp
#define Simulation_cpp

#include "Simulation.hpp"
#include <pceLogger/pceLogger.hpp>

namespace pce {
namespace {
const std::string log_name = "Simulation";
}

/* initialize static variables */
//SDL_Renderer* Simulation::renderer = nullptr;
//std::vector<SDL_Event> Simulation::frame_events;
//SDL_Event Simulation::event;
//bool Simulation::isRunning = true;


void Simulation::init(const char* title,
                      int width,
                      int height,
                      int xpos,
                      int ypos,
                      bool fullscreen)
{
    LOG_DEBUG(log_name) << "Initing screen with:\n"
                        << " title: " << title << '\n'
                        << " width: " << width << '\n'
                        << " height: " << height << '\n'
                        << " xpos: " << xpos << '\n'
                        << " ypos: " << ypos << '\n';

    int flags = 0;  
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        LOG_DEBUG(log_name) << "Subsystems initialized";

        window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window_ != nullptr)
        {
            LOG_DEBUG(log_name) << "Window created";
        }

        renderer = SDL_CreateRenderer(window_, -1, 0);
        if(renderer != nullptr)
        {
            LOG_DEBUG(log_name) << "Renderer created";
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            LOG_DEBUG(log_name) << "Renderer color set";
        }
        else
        {
            LOG_ERROR(log_name) << "Renderer creation failed.";
        }
    }
}


void Simulation::handleEvents()
{
    while (SDL_PollEvent(&event))
        frame_events.push_back(event);

    for (auto const& m_event : frame_events)
    {
        switch (m_event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}


void Simulation::clearFrameEvents() { frame_events.clear(); }
void Simulation::render()           { SDL_RenderPresent(renderer); }
void Simulation::clearRenderer()    { SDL_RenderClear(renderer); }

void Simulation::clean()
{
    SDL_DestroyWindow( window_ );
    SDL_DestroyRenderer( renderer );
    SDL_Quit();
    LOG_DEBUG(log_name) << "Simulation cleaned";
}



}



#endif /* Simulation_cpp */
