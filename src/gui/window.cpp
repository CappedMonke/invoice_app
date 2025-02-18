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
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);
}

void Window::handle_event(const SDL_Event *event) {
    // switch (event->type) {
    // case SDL_EVENT_WINDOW_RESIZED:
    //     Clay_SetLayoutDimensions((Clay_Dimensions){(float)event->window.data1, (float)event->window.data2});
    //     break;
    // case SDL_EVENT_MOUSE_MOTION:
    //     Clay_SetPointerState((Clay_Vector2){event->motion.x, event->motion.y}, event->motion.state & SDL_BUTTON_LMASK);
    //     break;
    // case SDL_EVENT_MOUSE_BUTTON_DOWN:
    //     Clay_SetPointerState((Clay_Vector2){event->button.x, event->button.y}, event->button.button == SDL_BUTTON_LEFT);
    //     break;
    // case SDL_EVENT_MOUSE_WHEEL:
    //     Clay_UpdateScrollContainers(true, (Clay_Vector2){event->wheel.x, event->wheel.y}, 0.01f);
    //     break;
    // }
}

uint32_t Window::get_id() {
    return SDL_GetWindowID(window);
}
