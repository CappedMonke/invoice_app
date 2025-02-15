#include "main_window.hpp"

#include "button.hpp"

Main_window::Main_window(const char *title, int w, int h, uint32_t flags)
    : Window(title, w, h, flags) {
    Button *button = new Button(0, 0, 200, 100, 255, 0, 0, 255);
    ui_components.push_back(button);
}
