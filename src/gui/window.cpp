#include "window.hpp"

#include "managers/window_manager.hpp"

Window::Window(const char *title, int width, int height, uint32_t flags) {
    window = SDL_CreateWindow(title, width, height, flags);
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
}

void Window::update() {
    for (auto ui_component : ui_components) {
        ui_component->render(renderer);
    }
}

void Window::handle_event(const SDL_Event *event) {
    for (auto ui_component : ui_components) {
        ui_component->handle_event(event);
    }
}

uint32_t Window::get_id() {
    return id;
}
