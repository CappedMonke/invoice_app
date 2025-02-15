#pragma once

#include "ui_element.hpp"

class Container : public Ui_element {
public:
    virtual ~Container();

    virtual void update(float delta_time) override;
};

class Vertical_container : public Container {
public:
    virtual void update(float delta_time) override;
};

class Horizontal_container : public Container {
public:
    virtual void update(float delta_time) override;
};