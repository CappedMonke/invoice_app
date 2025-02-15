#pragma once

#include <SDL3/SDL.h>

class Ui_component {
public:
    virtual ~Ui_component() = default;

    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void handle_event(const SDL_Event *event) = 0;
};