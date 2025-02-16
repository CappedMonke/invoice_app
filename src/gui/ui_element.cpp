#include "ui_element.hpp"

#include <algorithm>

Ui_element::~Ui_element() {
    for (auto const &element : elements) {
        delete element;
    }
}

void Ui_element::update(float delta_time) {
    for (auto const &element : elements) {
        element->update(delta_time);
    }
}

void Ui_element::render(SDL_Renderer *renderer) {
    if (!is_visible) {
        return;
    }

    for (auto const &element : elements) {
        element->render(renderer);
    }
}

void Ui_element::handle_event(const SDL_Event *event) {
    for (auto const &element : elements) {
        element->handle_event(event);
    }
}

void Ui_element::add_element(Ui_element *element) {
    elements.push_back(element);
    element->parent = this;
}

void Ui_element::remove_element(Ui_element *element) {
    elements.erase(std::remove(elements.begin(), elements.end(), element), elements.end());
    delete element;
}
