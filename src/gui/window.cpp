#include "window.hpp"

#include "layout.hpp"

Window::Window(const char *title, int w, int h, uint32_t flags, Layout *layout)
    : layout(layout) {
    window = SDL_CreateWindow(title, w, h, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }

    if (layout == nullptr) {
        SDL_Log("Window created without layout");
    }
}

Window::~Window() {
    delete layout;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::update() {
    layout->update();

    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    layout->render(renderer);
    SDL_RenderPresent(renderer);
}

void Window::handle_event(const SDL_Event *event) {
    layout->handle_event(event);
}

uint32_t Window::get_id() {
    return SDL_GetWindowID(window);
}
