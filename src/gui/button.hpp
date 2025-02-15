#pragma once

#include "ui_component.hpp"

class Button : public Ui_component {
public:
    Button(float x, float y, float w, float h, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    virtual void render(SDL_Renderer *renderer);
    virtual void handle_event(const SDL_Event *event);

protected:
    virtual void activate();

private:
    float x, y, w, h;
    Uint8 r, g, b, a;
    bool is_hovered = false;
    bool is_down = false;

    void hover();
    void down();
    void release();
};