#pragma once

#include "ui_element.hpp"

#include <string>

#include "utils/colors.hpp"

class Button : public Ui_element {
public:
    virtual void render(SDL_Renderer *renderer) override;
    virtual void handle_event(const SDL_Event *event) override;

    std::function<void()> on_execute_callback;

    SDL_Color color_default = Color::gray_4;
    SDL_Color color_hover = Color::gray_5;
    SDL_Color color_pressed = Color::gray_6;
    SDL_Color color_current = color_default;

private:
    bool is_pressed = false;
    bool was_mouse_inside = false;

    void on_press();
    void on_mouse_enter();
    void on_mouse_exit();
    void on_release();
};