#include "panel.hpp"

void Panel::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = {position.x + render_offset.x, position.y + render_offset.y, size.x, size.y};
    SDL_RenderFillRect(renderer, &rect);

    Ui_element::render(renderer);
}