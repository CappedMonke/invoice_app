#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "core/database_manager.hpp"
#include "core/event_manager.hpp"
#include "core/window_manager.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    Database_manager::get_instance().start_up();
    Window_manager::get_instance().start_up();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) { return SDL_APP_CONTINUE; }

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    return Event_manager::get_instance().handle_event(event);
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    Window_manager::get_instance().shut_down();
    Database_manager::get_instance().shut_down();
};