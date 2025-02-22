#include "ui_element.hpp"

#include <algorithm>

Ui_element::~Ui_element() {
    for (auto child : children) {
        delete child;
    }
}

void Ui_element::update(float delta_time) {
    for (auto child : children) {
        child->update(delta_time);
    }

    set_size_to_min_size();
}

void Ui_element::handle_event(const SDL_Event *event) {
    for (auto child : children) {
        child->handle_event(event);
    }
}

void Ui_element::render(SDL_Renderer *renderer) {
    for (auto child : children) {
        child->render(renderer);
    }
}

void Ui_element::add_child(Ui_element *child) {
    children.push_back(child);
    child->parent = this;
}

void Ui_element::remove_child(Ui_element *child) {
    auto it = std::find(children.begin(), children.end(), child);
    if (it != children.end()) {
        children.erase(it);
        child->parent = nullptr;
    }
}

void Ui_element::set_size_to_min_size() {
    if (size.x < min_size.x) {
        size.x = min_size.x;
    }
    if (size.y < min_size.y) {
        size.y = min_size.y;
    }
}
