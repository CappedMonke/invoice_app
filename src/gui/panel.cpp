#include "panel.hpp"

void Panel::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_FRect rect = {position.x, position.y, size.x, size.y};
    SDL_RenderFillRect(renderer, &rect);

    Ui_element::render(renderer);
}