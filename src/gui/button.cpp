#include "button.hpp"

void Button::update() {
}

void Button::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color_current.r, color_current.g, color_current.b, color_current.a);
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
        if (is_pressed) {
            if (was_mouse_inside) {
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
    color_current = color_pressed;
}

void Button::on_mouse_enter() {
    color_current = is_pressed ? color_pressed : color_hover;
}

void Button::on_mouse_exit() {
    color_current = is_pressed ? color_pressed : color_default;
}

void Button::on_release() {
    color_current = was_mouse_inside ? color_hover : color_default;
}