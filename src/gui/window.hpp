#pragma once

#include <SDL3/SDL.h>
#include <vector>

#define CLAY_IMPLEMENTATION
#include <clay.h>
#include <examples/shared-layouts/clay-video-demo.c>
#include <renderers/SDL3/clay_renderer_SDL3.c>

class Window {
public:
    Window(const char *title, int w, int h, uint32_t flags);
    virtual ~Window();

    void update(float delta_time);
    void handle_event(const SDL_Event *event);

    uint32_t get_id();

private:
    SDL_Window *window;
    Clay_SDL3RendererData renderer_data;
    ClayVideoDemo_Data demo_data;
};