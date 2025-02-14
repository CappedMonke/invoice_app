#include "window_manager.hpp"

#include <algorithm>

#include <utils/config.hpp>

Window_manager &Window_manager::get_instance() {
    static Window_manager instance;
    return instance;
}

void Window_manager::start_up() {
    create_window(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
}

void Window_manager::shut_down() {
    close_all_windows();
}

void Window_manager::create_window(const char *title, int w, int h, SDL_WindowFlags flags) {
    SDL_Window *window = SDL_CreateWindow(title, w, h, flags);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }
    uint32_t window_id = SDL_GetWindowID(window);
    windows[window_id] = window;
    SDL_Log("Window created: %s (%i)", title, window_id);
}

void Window_manager::close_window(SDL_Window *window) {
    int32_t window_id = SDL_GetWindowID(window);
    close_window_by_id(window_id);
}

void Window_manager::close_window_by_id(uint32_t window_id) {
    auto it = windows.find(window_id);
    if (it != windows.end()) {
        SDL_DestroyWindow(it->second);
        windows.erase(it);
        SDL_Log("Window closed: %i", window_id);
    }
}

void Window_manager::close_all_windows() {
    for (auto &pair : windows) {
        SDL_DestroyWindow(pair.second);
    }
    windows.clear();
    SDL_Log("All windows closed");
}