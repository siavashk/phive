#include "eventloop.h"

using namespace phive;
using namespace core;

EventLoop::EventLoop()
    : quit_(false)
{
    listen();
}

EventLoop::~EventLoop()
{
}

void EventLoop::listen()
{
    while (!quit_)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit_ = true;
                    break;
                
                default:
                    break;
            }
        }
        SDL_Delay(16);
    }
    
}
