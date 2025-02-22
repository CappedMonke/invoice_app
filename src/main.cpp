#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "managers/database_manager.hpp"
#include "managers/window_manager.hpp"

Database_manager &database_manager = Database_manager::get_instance();
Window_manager &window_manager = Window_manager::get_instance();

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
    }

    // if (!TTF_Init()) {
    //     SDL_Log("Failed to initialize SDL_ttf: %s", SDL_GetError());
    // }

    // database_manager.start_up();
    window_manager.start_up();

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    static uint64_t last_time;
    uint64_t current_time = SDL_GetTicks();
    float delta_time = (current_time - last_time) / 1000.0;
    last_time = current_time;

    window_manager.update(delta_time);

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
    // database_manager.shut_down();
    // TTF_Quit();
}
