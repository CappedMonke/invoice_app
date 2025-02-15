#include "container.hpp"

Container::~Container() {
    for (auto const &element : elements) {
        delete element;
    }
}

void Container::update(float delta_time) {
    for (auto const &element : elements) {
        element->pos = pos;
        if (element->expand_x) {
            element->size.x = size.x;
        }
        if (element->expand_y) {
            element->size.y = size.y;
        }
    }

    Ui_element::update(delta_time);
}

void Vertical_container::update(float delta_time) {
    float total_proportion = 0;
    for (auto const &element : elements) {
        total_proportion += element->proportion;
    }

    float y = pos.y;
    for (auto const &element : elements) {
        element->pos.y = y;
        element->pos.x = pos.x;
        element->size.x = size.x;
        element->size.y = size.y * element->proportion / total_proportion;
        y += element->size.y;
    }

    Ui_element::update(delta_time);
}

void Horizontal_container::update(float delta_time) {
    float total_proportion = 0;
    for (auto const &element : elements) {
        total_proportion += element->proportion;
    }

    float x = pos.x;
    for (auto const &element : elements) {
        element->pos.x = x;
        element->pos.y = pos.y;
        element->size.x = size.x * element->proportion / total_proportion;
        element->size.y = size.y;
        x += element->size.x;
    }

    Ui_element::update(delta_time);
}
