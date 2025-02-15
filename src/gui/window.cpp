#include "window.hpp"

#include "managers/window_manager.hpp"

Window::Window(const char *title, int w, int h, uint32_t flags) {
    window = SDL_CreateWindow(title, w, h, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }
    id = SDL_GetWindowID(window);

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }
}

Window::~Window() {
    for (auto ui_component : ui_components) {
        delete ui_component;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::render() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    for (auto ui_component : ui_components) {
        ui_component->render(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Window::handle_event(const SDL_Event *event) {
    for (auto ui_component : ui_components) {
        ui_component->handle_event(event);
    }
}

uint32_t Window::get_id() {
    return id;
}
