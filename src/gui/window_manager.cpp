#include "window_manager.h"

#include <algorithm>

Window_manager::Window_manager() {
    windows.push_back(new Window("Window 1", 400, 600, SDL_WINDOW_RESIZABLE));
    windows.push_back(new Window("Window 2", 400, 600, SDL_WINDOW_RESIZABLE));
}

Window_manager::~Window_manager() {
    for (auto& window : windows) {
        delete window;
    }
}

void Window_manager::render() {
    for (auto& window : windows) {
        window->render();
    }
}

bool Window_manager::handle_events(SDL_Event* event) {
    for (int i = 0; i < windows.size(); i++) {
        if (!windows[i]->handle_events(event)) {
            if (windows.size() <= 1) {
                return false;
            }
            delete windows[i];
            windows.erase(windows.begin() + i);
        }
    }
    return true;
}