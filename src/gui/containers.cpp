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

void Container::compute_size() {
    Ui_element::compute_size();

    float container_min_size_x = min_size.x;
    float container_min_size_y = min_size.y;

    for (auto &child : children) {
        container_min_size_x = std::max(container_min_size_x, child->size.x);
        container_min_size_y = std::max(container_min_size_y, child->size.y);
    }

    container_min_size_x += padding[1] + padding[3];
    container_min_size_y += padding[0] + padding[2];

    size.x = container_min_size_x > min_size.x ? container_min_size_x : min_size.x;
    size.y = container_min_size_y > min_size.y ? container_min_size_y : min_size.y;
}

void Container::compute_layout() {
    float free_space_x = size.x - padding[1] - padding[3];
    float free_space_y = size.y - padding[0] - padding[2];

    float x = position.x + padding[3];
    float y = position.y + padding[0];

    for (auto &child : children) {
        child->position.x = x;
        child->position.y = y;

        child->size.x = child->expand_x ? free_space_x : child->size.x;
        child->size.y = child->expand_y ? free_space_y : child->size.y;
    }

    Ui_element::compute_layout();
}

void Vertical_container::compute_size() {
    Ui_element::compute_size();

    float total_spacing = children.size() > 1 ? spacing * (children.size() - 1) : 0;

    float container_min_size_x = min_size.x;
    float container_min_size_y = 0;

    for (auto &child : children) {
        container_min_size_x = std::max(container_min_size_x, child->size.x);
        container_min_size_y += child->size.y;
    }

    container_min_size_x += padding[1] + padding[3];
    container_min_size_y += padding[0] + padding[2] + total_spacing;

    size.x = container_min_size_x > min_size.x ? container_min_size_x : min_size.x;
    size.y = container_min_size_y > min_size.y ? container_min_size_y : min_size.y;
}

void Vertical_container::compute_layout() {
    float total_spacing = children.size() > 1 ? spacing * (children.size() - 1) : 0;

    float free_space_x = size.x - padding[1] - padding[3];
    float free_space_y = size.y - padding[0] - padding[2] - total_spacing;

    float total_propotion = 0;

    for (auto &child : children) {
        free_space_y -= child->size.y;
        if (child->expand_y) {
            total_propotion += child->proportion;
        }
    }

    float x = position.x + padding[3];
    float y = position.y + padding[0];

    for (auto &child : children) {
        child->position.x = x;
        child->position.y = y;

        child->size.x = child->expand_x ? free_space_x : child->size.x;
        child->size.y = child->expand_y ? child->size.y + free_space_y * child->proportion / total_propotion : child->size.y;

        y += child->size.y + spacing;
    }

    Ui_element::compute_layout();
}

void Horizontal_container::compute_size() {
    Ui_element::compute_size();

    float total_spacing = children.size() > 1 ? spacing * (children.size() - 1) : 0;

    float container_min_size_x = 0;
    float container_min_size_y = min_size.y;

    for (auto &child : children) {
        container_min_size_x += child->size.x;
        container_min_size_y = std::max(container_min_size_y, child->size.y);
    }

    container_min_size_x += padding[1] + padding[3] + total_spacing;
    container_min_size_y += padding[0] + padding[2];

    size.x = container_min_size_x > min_size.x ? container_min_size_x : min_size.x;
    size.y = container_min_size_y > min_size.y ? container_min_size_y : min_size.y;
}

void Horizontal_container::compute_layout() {
    float total_spacing = children.size() > 1 ? spacing * (children.size() - 1) : 0;

    float free_space_x = size.x - padding[1] - padding[3] - total_spacing;
    float free_space_y = size.y - padding[0] - padding[2];

    float total_propotion = 0;

    for (auto &child : children) {
        free_space_x -= child->size.x;
        if (child->expand_x) {
            total_propotion += child->proportion;
        }
    }

    float x = position.x + padding[3];
    float y = position.y + padding[0];

    for (auto &child : children) {
        child->position.x = x;
        child->position.y = y;

        child->size.x = child->expand_x ? child->size.x + free_space_x * child->proportion / total_propotion : child->size.x;
        child->size.y = child->expand_y ? free_space_y : child->size.y;

        x += child->size.x + spacing;
    }

    Ui_element::compute_layout();
}
