#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "ui_element.hpp"

class Window {
public:
    Window(const char *title, int w, int h, uint32_t flags, Ui_element *view);
    ~Window();

    void update(float delta_time);
    void handle_event(const SDL_Event *event);

    uint32_t get_id();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Ui_element *view;
};