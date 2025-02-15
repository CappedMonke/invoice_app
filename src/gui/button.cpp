#include "button.hpp"

#include "main_window.hpp"
#include <managers/window_manager.hpp>

Button::Button(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
    : x(x), y(y), w(w), h(h), r(r), g(g), b(b), a(a) {}

void Button::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_FRect rect = {x, y, w, h};
    SDL_RenderFillRect(renderer, &rect);
}

void Button::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        if (event->motion.x >= x && event->motion.x <= x + w && event->motion.y >= y && event->motion.y <= y + h) {
            hover();
        } else {
            is_hovered = false;
        }
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT && is_hovered) {
        down();
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && event->button.button == SDL_BUTTON_LEFT && is_down) {
        release();
    }
}

void Button::activate() {
    SDL_Log("Button activated");
    Window_manager::get_instance().open_window<Main_window>();
}

void Button::hover() {
    is_hovered = true;
}

void Button::down() {
    is_down = true;
}

void Button::release() {
    if (is_hovered) {
        activate();
    }
    is_down = false;
}
