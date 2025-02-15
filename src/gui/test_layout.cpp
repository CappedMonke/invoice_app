#include "test_layout.hpp"

#include "button.cpp"

Test_layout::Test_layout() {
    Button *button = new Button();
    button->size = {100, 50};
    button->on_execute_callback = []() {
        SDL_Log("Button clicked");
    };
    elements.push_back(button);
}