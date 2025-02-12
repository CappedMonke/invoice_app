#include "window.h"

Window::Window(const char* title, int x, int y, SDL_WindowFlags flags) {
    window = SDL_CreateWindow(title, x, y, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }
}

Window::~Window() {
    for (auto& ui_element : ui_elements) {
        delete ui_element;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::render() {
    for (auto& ui_element : ui_elements) {
        ui_element->render(renderer);
    }
}

bool Window::handle_events(SDL_Event* event) {
    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event->window.windowID == SDL_GetWindowID(window)) {
        return false;
    }

    for (auto& ui_element : ui_elements) {
        ui_element->handle_events(event);
    }

    return true;
}
