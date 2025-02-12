#pragma once

#include <SDL3/SDL.h>
#include <vector>

#include "ui_element.h"

class Window {
public:
    Window(const char* title, int x, int y, SDL_WindowFlags flags);
    ~Window();

    void render();
    bool handle_events(SDL_Event* event);

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    std::vector<Ui_element*> ui_elements;
};