#pragma once

#include "ui_element.hpp"

#include <vector>

class Layout : public Ui_element {
public:
    virtual ~Layout() override;

    virtual void update() override;
    virtual void render(SDL_Renderer *renderer) override;
    virtual void handle_event(const SDL_Event *event) override;

protected:
    std::vector<Ui_element *> elements;
};