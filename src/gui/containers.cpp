#include "containers.h"

#include "utils/colors.hpp"

void Container::update(float delta_time) {
    if (size.x < min_size.x) {
        size.x = min_size.x;
    }
    if (size.y < min_size.y) {
        size.y = min_size.y;
    }

    Ui_element::update(delta_time);
}

void Container::render(SDL_Renderer *renderer) {
#if !NDEBUG && 1
    SDL_SetRenderDrawColor(renderer, Color::red_4.r, Color::red_4.g, Color::red_4.b, Color::red_4.a);
    SDL_FRect rect = {position.x, position.y, size.x, size.y};
    SDL_RenderRect(renderer, &rect);
#endif

    Ui_element::render(renderer);
}

void Vertical_container::update(float delta_time) {
}

void Horizontal_container::update(float delta_time) {
}
