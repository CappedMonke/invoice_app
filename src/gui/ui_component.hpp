#pragma once

#include <SDL3/SDL.h>

class Ui_component {
public:
    Ui_component() = default;
    virtual ~Ui_component() = default;

    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void handle_event(const SDL_Event *event) = 0;
};