#pragma once

#include "ui_element.hpp"

class Container : public Ui_element {
public:
    virtual void render(SDL_Renderer *renderer) override;

protected:
    glm::vec4 padding = {0, 0, 0, 0};
    float spacing = 0;
};

class Vertical_container : public Container {
public:
    virtual void compute_size() override;
    virtual void compute_layout() override;
};

class Horizontal_container : public Container {
public:
    virtual void compute_size() override;
    virtual void compute_layout() override;
};