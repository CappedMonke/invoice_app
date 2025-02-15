#include "window_manager.hpp"

#include <SDL3/SDL.h>

#include "gui/main_window.hpp"
#include "gui/window.hpp"

Window_manager &Window_manager::get_instance() {
    static Window_manager instance;
    return instance;
}

void Window_manager::start_up() {
    open_window<Main_window>();
}

void Window_manager::shut_down() {
    close_all_windows();
}

void Window_manager::handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        close_window_by_id(event->window.windowID);
    }

    if (event->type == SDL_EVENT_WINDOW_FOCUS_GAINED) {
        active_window_id = event->window.windowID;
    }

    if (active_window_id != 0) {
        windows[active_window_id]->handle_event(event);
    }
}

void Window_manager::update() {
    if (active_window_id != 0) {
        windows[active_window_id]->render();
    }
}

void Window_manager::close_all_windows() {
    for (auto const &window : windows) {
        close_window_by_id(window.first);
    }
}

template <typename Window_class>
void Window_manager::open_window() {
    Window *window = new Window_class();
    uint32_t window_id = window->get_id();
    windows[window_id] = window;
    active_window_id = window_id;
}

void Window_manager::close_window(Window *window) {
    close_window_by_id(window->get_id());
}

void Window_manager::close_window_by_id(uint32_t window_id) {
    delete windows[window_id];
    windows.erase(window_id);
    active_window_id = 0;
}
