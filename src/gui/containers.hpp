#pragma once

#include "ui_element.hpp"

struct Padding {
    float up = 0.0;
    float down = 0.0;
    float left = 0.0;
    float right = 0.0;
};

class Container : public Ui_element {
public:
    virtual void update(float delta_time) override;

protected:
    Padding padding;
};

class Vertical_container : public Container {
public:
    virtual void update(float delta_time) override;
};

class Horizontal_container : public Container {
public:
    virtual void update(float delta_time) override;
};