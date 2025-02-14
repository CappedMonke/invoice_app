#pragma once

#include <SDL3/SDL.h>
#include <unordered_map>

class Window_manager {
public:
    static Window_manager &get_instance();

    void start_up();
    void shut_down();

    void create_window(const char *title, int w, int h, SDL_WindowFlags flags);
    void close_window(SDL_Window *window);
    void close_window_by_id(uint32_t window_id);
    void close_all_windows();

private:
    std::unordered_map<uint32_t, SDL_Window *> windows;
};