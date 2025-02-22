#include "containers.hpp"

#include "utils/colors.hpp"
#include "utils/config.hpp"

void Container::render(SDL_Renderer *renderer) {
    Ui_element::render(renderer);

#if !NDEBUG && DEBUG_GUI
    SDL_SetRenderDrawColor(renderer, Color::red_4.r, Color::red_4.g, Color::red_4.b, Color::red_4.a);
    SDL_FRect rect = {position.x, position.y, size.x, size.y};
    SDL_RenderRect(renderer, &rect);
#endif
}

void Vertical_container::compute_size() {
    Ui_element::compute_size();

    glm::vec2 container_min_size = {min_size.x, 0};
    for (auto &child : children) {
        container_min_size.x = std::max(container_min_size.x, child->size.x);
        container_min_size.y += child->size.y;
    }

    size.x = container_min_size.x > min_size.x ? container_min_size.x : min_size.x;
    size.y = container_min_size.y > min_size.y ? container_min_size.y : min_size.y;
}

void Vertical_container::compute_layout() {
    float free_space_y = size.y;
    float total_propotion = 0;
    for (auto &child : children) {
        free_space_y -= child->size.y;
        if (child->expand_y) {
            total_propotion += child->proportion;
        }
    }

    float y = position.y;
    for (auto &child : children) {
        child->position.x = position.x;
        child->position.y = y;
        child->size.x = child->expand_x ? size.x : child->size.x;
        child->size.y = child->expand_y ? child->size.y + free_space_y * child->proportion / total_propotion : child->size.y;
        y += child->size.y;
    }

    Ui_element::compute_layout();
}

void Horizontal_container::compute_size() {
    Ui_element::compute_size();

    glm::vec2 container_min_size = {0, min_size.y};
    for (auto &child : children) {
        container_min_size.x += child->size.x;
        container_min_size.y = std::max(container_min_size.y, child->size.y);
    }

    size.x = container_min_size.x > min_size.x ? container_min_size.x : min_size.x;
    size.y = container_min_size.y > min_size.y ? container_min_size.y : min_size.y;
}

void Horizontal_container::compute_layout() {
    float free_space_x = size.x;
    float total_propotion = 0;
    for (auto &child : children) {
        free_space_x -= child->size.x;
        if (child->expand_x) {
            total_propotion += child->proportion;
        }
    }

    float x = position.x;
    for (auto &child : children) {
        child->position.x = x;
        child->position.y = position.y;
        child->size.x = child->expand_x ? child->size.x + free_space_x * child->proportion / total_propotion : child->size.x;
        child->size.y = child->expand_y ? size.y : child->size.y;
        x += child->size.x;
    }

    Ui_element::compute_layout();
}
