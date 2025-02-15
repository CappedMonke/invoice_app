#pragma once

#include "ui_element.hpp"

#include <string>

class Button : public Ui_element {
public:
    virtual void update() override;
    virtual void render(SDL_Renderer *renderer) override;
    virtual void handle_event(const SDL_Event *event) override;

    std::function<void()> on_execute_callback;

private:
    bool is_pressed = false;
    bool was_mouse_inside = false;

    void on_press();
    void on_mouse_enter();
    void on_mouse_exit();
    void on_release();
};