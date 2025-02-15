#pragma once

#include <glm/glm.hpp>
#include <SDL3/SDL.h>

class Ui_element {
public:
    virtual ~Ui_element() = default;

    virtual void update() = 0;
    virtual void render(SDL_Renderer *renderer) = 0;
    virtual void handle_event(const SDL_Event *event) = 0;

    bool is_visible = true;

    glm::vec2 pos = {0, 0};
    glm::vec2 size = {100, 100};
};