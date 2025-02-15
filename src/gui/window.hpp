#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "ui_component.hpp"

class Window {
public:
    Window(const char *title = "Window", int width = 1280 / 2, int height = 1024 / 2, uint32_t flags = SDL_WINDOW_RESIZABLE);
    virtual ~Window();

    virtual void update();
    virtual void handle_event(const SDL_Event *event);

    uint32_t get_id();

private:
    uint32_t id;
    const char *title;
    int width;
    int height;
    uint32_t flags;

    SDL_Window *window;
    SDL_Renderer *renderer;

    std::vector<Ui_component *> ui_components;
};