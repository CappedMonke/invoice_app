#include "event_manager.hpp"

#include <algorithm>

#include "window_manager.hpp"

Event_manager &Event_manager::get_instance() {
    static Event_manager instance;
    return instance;
}

SDL_AppResult Event_manager::handle_event(SDL_Event *event) {
    auto handler = event_handlers.find(static_cast<SDL_EventType>(event->type));
    if (handler != event_handlers.end()) {
        for (auto callback : handler->second) {
            callback(event);
        }
    }

    if (event->type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        uint32_t window_id = event->window.windowID;
        Window_manager::get_instance().close_window_by_id(window_id);
    }

    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    return SDL_APP_CONTINUE;
}

void Event_manager::register_event_handler(SDL_EventType type, void (*callback)(SDL_Event *)) {
    event_handlers[type].push_back(callback);
}

void Event_manager::clear_event_handlers() {
    event_handlers.clear();
}