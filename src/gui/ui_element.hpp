#pragma once

#include <glm/glm.hpp>
#include <SDL3/SDL.h>
#include <vector>

class Ui_element {
public:
    virtual ~Ui_element();

    virtual void update(float delta_time);
    virtual void handle_event(const SDL_Event *event);
    virtual void render(SDL_Renderer *renderer);

    virtual void add_child(Ui_element *child);
    virtual void remove_child(Ui_element *child);

    virtual void compute_size();
    virtual void compute_layout();

    bool expand_x = true;
    bool expand_y = true;
    float proportion = 1;

    glm::vec2 position = {0, 0};
    glm::vec2 size = {0, 0};
    glm::vec2 min_size = {0, 0};

protected:
    Ui_element *parent = nullptr;
    std::vector<Ui_element *> children;
};