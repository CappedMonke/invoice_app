#include "containers.hpp"

#include "utils/colors.hpp"

void Container::render(SDL_Renderer *renderer) {
    Ui_element::render(renderer);

#if !NDEBUG && 1
    SDL_SetRenderDrawColor(renderer, Color::red_4.r, Color::red_4.g, Color::red_4.b, Color::red_4.a);
    SDL_FRect rect = {position.x, position.y, size.x, size.y};
    SDL_RenderRect(renderer, &rect);
#endif
}

void Vertical_container::update(float delta_time) {
    Ui_element::update(delta_time);

    float y = position.y;
    for (auto child : children) {
        child->position.x = position.x;
        child->position.y = y;
        y += child->size.y;
    }
}

void Horizontal_container::update(float delta_time) {
    Ui_element::update(delta_time);

    float x = position.x;
    for (auto child : children) {
        child->position.x = x;
        child->position.y = position.y;
        x += child->size.x;
    }
}
