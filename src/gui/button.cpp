#include "button.hpp"

void Button::update() {
}

void Button::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_FRect rect = {pos.x, pos.y, size.x, size.y};
    SDL_RenderFillRect(renderer, &rect);
}

void Button::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        bool is_mouse_inside = event->motion.x >= pos.x && event->motion.x <= pos.x + size.x && event->motion.y >= pos.y && event->motion.y <= pos.y + size.y;
        if (!was_mouse_inside && is_mouse_inside) {
            on_mouse_enter();
        } else if (was_mouse_inside && !is_mouse_inside) {
            on_mouse_exit();
        }
        was_mouse_inside = is_mouse_inside;
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && event->button.button == SDL_BUTTON_LEFT) {
        if (was_mouse_inside) {
            on_press();
            is_pressed = true;
        }
    } else if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && event->button.button == SDL_BUTTON_LEFT) {
        if (was_mouse_inside) {
            if (is_pressed) {
                if (on_execute_callback) {
                    on_execute_callback();
                } else {
                    SDL_Log("Button has no on_execute_callback");
                }
            }
            on_release();
            is_pressed = false;
        }
    }
}

void Button::on_press() {
}

void Button::on_mouse_enter() {
}

void Button::on_mouse_exit() {
}

void Button::on_release() {
}