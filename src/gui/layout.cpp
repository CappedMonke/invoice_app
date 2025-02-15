#include "layout.hpp"

Layout::~Layout() {
    for (auto element : elements) {
        delete element;
    }
}

void Layout::update() {
    for (auto element : elements) {
        element->update();
    }
}

void Layout::render(SDL_Renderer *renderer) {
    for (auto element : elements) {
        element->render(renderer);
    }
}

void Layout::handle_event(const SDL_Event *event) {
    for (auto element : elements) {
        element->handle_event(event);
    }
}

void Layout::add_element(Ui_element *element) {
    elements.push_back(element);
}
