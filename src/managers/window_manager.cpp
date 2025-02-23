#include "window_manager.hpp"

#include <SDL3/SDL.h>

#include "gui/window.hpp"
#include "views/main_view.hpp"

Window_manager &Window_manager::get_instance() {
    static Window_manager instance;
    return instance;
}

void Window_manager::start_up() {
    open_window("Rechnungen", 1200 * 0.8, 1024 * 0.8, SDL_WINDOW_RESIZABLE, create_main_view());
}

void Window_manager::shut_down() {
    close_all_windows();
}

void Window_manager::update(float delta_time) {
    if (active_window_id != 0) {
        windows[active_window_id]->update(delta_time);
    }
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

void Window_manager::open_window(const char *title, int w, int h, uint32_t flags, Ui_element *view) {
    Window *window = new Window(title, w, h, flags, view);
    view->min_size = {w, h};
    uint32_t window_id = window->get_id();
    windows[window_id] = window;
    active_window_id = window_id;
}

void Window_manager::close_window_by_id(uint32_t window_id) {
    delete windows[window_id];
    windows.erase(window_id);
    active_window_id = 0;
}

void Window_manager::close_all_windows() {
    for (auto const &window : windows) {
        close_window_by_id(window.first);
    }
}