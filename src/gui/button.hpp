#pragma once

#include "gui/ui_element.hpp"

#include "utils/colors.hpp"

class Button : public Ui_element {
public:
    virtual void render(SDL_Renderer *renderer) override;
    virtual void handle_event(const SDL_Event *event) override;

    std::function<void()> on_click;

    SDL_Color color_normal = Color::gray_5;
    SDL_Color color_hover = Color::gray_6;
    SDL_Color color_click = Color::gray_7;

private:
    bool is_hovered = false;
    bool is_clicked = false;
};