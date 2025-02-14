#pragma once

#include <map>
#include <SDL3/SDL.h>
#include <vector>

class Event_manager {
public:
    static Event_manager &get_instance();

    SDL_AppResult handle_event(SDL_Event *event);
    void register_event_handler(SDL_EventType type, void (*callback)(SDL_Event *));
    void clear_event_handlers();

private:
    std::map<SDL_EventType, std::vector<void (*)(SDL_Event *)>> event_handlers;
};