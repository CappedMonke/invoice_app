#include "button.hpp"

void Button::render(SDL_Renderer *renderer) {
    if (is_clicked) {
        SDL_SetRenderDrawColor(renderer, color_click.r, color_click.g, color_click.b, color_click.a);
    } else if (is_hovered) {
        SDL_SetRenderDrawColor(renderer, color_hover.r, color_hover.g, color_hover.b, color_hover.a);
    } else {
        SDL_SetRenderDrawColor(renderer, color_normal.r, color_normal.g, color_normal.b, color_normal.a);
    }

    SDL_FRect rect = {position.x, position.y, size.x, size.y};
    SDL_RenderFillRect(renderer, &rect);
}

void Button::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_MOUSE_MOTION) {
        is_hovered = event->motion.x >= position.x && event->motion.x < position.x + size.x && event->motion.y >= position.y && event->motion.y < position.y + size.y;
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN && is_hovered) {
        is_clicked = true;
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_UP && is_clicked) {
        is_clicked = false;
        if (on_click) {
            on_click();
        }
    }
}
