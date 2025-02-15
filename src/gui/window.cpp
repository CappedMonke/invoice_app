#include "window.hpp"

#include "ui_element.hpp"

Window::Window(const char *title, int w, int h, uint32_t flags, Ui_element *view)
    : view(view) {
    window = SDL_CreateWindow(title, w, h, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }

    if (view == nullptr) {
        SDL_Log("Window created without view");
    }
}

Window::~Window() {
    delete view;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::update(float delta_time) {
    view->update(delta_time);

    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    view->render(renderer);
    SDL_RenderPresent(renderer);
}

void Window::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_WINDOW_RESIZED) {
        view->size = {event->window.data1, event->window.data2};
    }
    view->handle_event(event);
}

uint32_t Window::get_id() {
    return SDL_GetWindowID(window);
}
