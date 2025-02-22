#pragma once

#include "ui_element.hpp"

#include "utils/colors.hpp"

class Panel : public Ui_element {
public:
    virtual void render(SDL_Renderer *renderer) override;

    SDL_Color color = Color::black;
};