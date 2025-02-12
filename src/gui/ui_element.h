#pragma once

#include <SDL3/SDL.h>

class Ui_element {
public:
    Ui_element() = default;
    virtual ~Ui_element() = default;

    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void handle_events(SDL_Event* event) = 0;
};