#pragma once

#include "ui_element.hpp"

class Container : public Ui_element {
public:
    virtual void render(SDL_Renderer *renderer) override;
};

class Vertical_container : public Container {
public:
    virtual void update(float delta_time) override;
};

class Horizontal_container : public Container {
public:
    virtual void update(float delta_time) override;
};