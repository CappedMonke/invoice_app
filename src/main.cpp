#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "core/event_manager.h"
#include "core/window_manager.h"

constexpr int SCREEN_WIDTH = 1280 / 2;
constexpr int SCREEN_HEIGHT = 1024 / 2;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    Window_manager &window_manager = Window_manager::get_instance();
    window_manager.create_window("Hello, SDL!", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
    window_manager.create_window("Hello, SDL! 2", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    return Event_manager::get_instance().handle_event(event);
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    Window_manager::get_instance().close_all_windows();
};