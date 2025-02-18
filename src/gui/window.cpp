#include "window.hpp"

Window::Window(const char *title, int w, int h, uint32_t flags) {
    window = SDL_CreateWindow(title, w, h, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::update(float delta_time) {
}

void Window::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
    }
}

uint32_t Window::get_id() {
    return SDL_GetWindowID(window);
}
