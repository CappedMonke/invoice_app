#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "ui_component.hpp"

class Window {
public:
    Window(const char *title = "Window", int w = 1280 / 2, int h = 1024 / 2, uint32_t flags = SDL_WINDOW_RESIZABLE);
    virtual ~Window();

    void render();
    void handle_event(const SDL_Event *event);

    uint32_t get_id();

protected:
    std::vector<Ui_component *> ui_components;

private:
    uint32_t id;
    const char *title;
    int width;
    int height;
    uint32_t flags;

    SDL_Window *window;
    SDL_Renderer *renderer;
};