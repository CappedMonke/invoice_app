#pragma once

#include "window.hpp"

class Main_window : public Window {
public:
    Main_window(const char *title = "Rechnungen", int w = 1280 / 2, int h = 1024 / 2, uint32_t flags = SDL_WINDOW_RESIZABLE);
};