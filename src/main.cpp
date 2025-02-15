#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "managers/database_manager.hpp"
#include "managers/window_manager.hpp"
#include "utils/profiler.hpp"

Database_manager &database_manager = Database_manager::get_instance();
Window_manager &window_manager = Window_manager::get_instance();

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    database_manager.start_up();
    window_manager.start_up();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    window_manager.update();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    window_manager.handle_event(event);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    window_manager.shut_down();
    database_manager.shut_down();
}
