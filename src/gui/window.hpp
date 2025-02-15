#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "layout.hpp"

class Window {
public:
    Window(const char *title, int w, int h, uint32_t flags, Layout *layout);
    virtual ~Window();

    void update();
    void handle_event(const SDL_Event *event);

    uint32_t get_id();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Layout *layout;
};