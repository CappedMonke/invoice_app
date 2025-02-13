#include "window_manager.h"
#include <algorithm>

Window_manager &Window_manager::get_instance() {
    static Window_manager instance;
    return instance;
}

SDL_Window *Window_manager::create_window(const char *title, int w, int h, SDL_WindowFlags flags) {
    SDL_Window *window = SDL_CreateWindow(title, w, h, flags);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return nullptr;
    }
    uint32_t window_id = SDL_GetWindowID(window);
    windows[window_id] = window;
    SDL_Log("Window created: %s (%i)", title, window_id);

    return window;
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