#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "window.h"

class Window_manager {
public:
    Window_manager();
    ~Window_manager();

    void render();
    bool handle_events(SDL_Event* event);

private:
    std::vector<Window*> windows;
};