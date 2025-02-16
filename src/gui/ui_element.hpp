#pragma once

#include <glm/glm.hpp>
#include <SDL3/SDL.h>
#include <vector>

class Ui_element {
public:
    virtual ~Ui_element();

    virtual void update(float delta_time);
    virtual void render(SDL_Renderer *renderer);
    virtual void handle_event(const SDL_Event *event);
    virtual void add_element(Ui_element *element);
    void remove_element(Ui_element *element);

    bool is_visible = true;

    glm::vec2 pos = {0, 0};
    glm::vec2 size = {100, 100};
    glm::vec2 min_size = {0, 0};
    glm::vec2 max_size = {0, 0};

    bool expand_x = true;
    bool expand_y = true;
    float proportion = 1.0f;

protected:
    Ui_element *parent = nullptr;
    std::vector<Ui_element *> elements;
};