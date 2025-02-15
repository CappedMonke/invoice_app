#pragma once

#include "ui_element.hpp"

#include <vector>

class Layout : public Ui_element {
public:
    virtual ~Layout() override;

    virtual void update() override;
    virtual void render(SDL_Renderer *renderer) override;
    virtual void handle_event(const SDL_Event *event) override;

    virtual void add_element(Ui_element *element);

    bool expand_x = false;
    bool expand_y = false;

    glm::vec2 max_size = {0, 0};
    glm::vec2 min_size = {0, 0};

protected:
    std::vector<Ui_element *> elements;
};