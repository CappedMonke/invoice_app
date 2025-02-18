#include "window.hpp"

constexpr uint32_t FONT_ID = 0;

SDL_Surface *sample_image;

static inline Clay_Dimensions SDL_MeasureText(Clay_StringSlice text, Clay_TextElementConfig *config, void *user_data) {
    TTF_Font **fonts = static_cast<TTF_Font **>(user_data);
    TTF_Font *font = fonts[config->fontId];
    int width, height;

    if (!TTF_GetStringSize(font, text.chars, text.length, &width, &height)) {
        SDL_Log("Failed to measure text: %s", SDL_GetError());
    }

    return (Clay_Dimensions){(float)width, (float)height};
}

void handle_clay_errors(Clay_ErrorData error_data) {
    SDL_Log("Clay error: %s", error_data.errorText.chars);
}

Window::Window(const char *title, int w, int h, uint32_t flags) {
    window = SDL_CreateWindow(title, w, h, flags);
    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
    }

    renderer_data.renderer = SDL_CreateRenderer(window, NULL);
    if (renderer_data.renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
    }

    renderer_data.textEngine = TTF_CreateRendererTextEngine(renderer_data.renderer);
    if (renderer_data.textEngine == nullptr) {
        SDL_Log("Failed to create text engine: %s", SDL_GetError());
    }

    renderer_data.fonts = static_cast<TTF_Font **>(SDL_calloc(1, sizeof(TTF_Font *)));
    if (renderer_data.fonts == nullptr) {
        SDL_Log("Failed to allocate memory for fonts: %s", SDL_GetError());
    }

    TTF_Font *font = TTF_OpenFont("assets/fonts/Roboto-Regular.ttf", 16);
    if (!font) {
        SDL_Log("Failed to open font: %s", SDL_GetError());
    }

    renderer_data.fonts[FONT_ID] = font;

    sample_image = IMG_Load("assets/images/icon.svg");

    uint64_t total_memory_size = Clay_MinMemorySize();
    Clay_Arena clay_memory = (Clay_Arena){
        .memory = static_cast<char *>(SDL_malloc(total_memory_size)),
        .capacity = total_memory_size};

    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    Clay_Initialize(clay_memory, (Clay_Dimensions){(float)width, (float)height}, (Clay_ErrorHandler){handle_clay_errors});
    Clay_SetMeasureTextFunction(SDL_MeasureText, renderer_data.fonts);

    demo_data = ClayVideoDemo_Initialize();
}

Window::~Window() {
    SDL_DestroyRenderer(renderer_data.renderer);
    SDL_DestroyWindow(window);
    for (size_t i = 0; i < sizeof(renderer_data.fonts) / sizeof(*renderer_data.fonts); i++) {
        if (renderer_data.fonts[i]) {
            TTF_CloseFont(renderer_data.fonts[i]);
        }
        SDL_free(renderer_data.fonts);
    }
    TTF_DestroyRendererTextEngine(renderer_data.textEngine);
}

void Window::update(float delta_time) {
    Clay_RenderCommandArray render_commands;

    SDL_SetRenderDrawColor(renderer_data.renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer_data.renderer);

    SDL_Clay_RenderClayCommands(&renderer_data, &render_commands);

    SDL_RenderPresent(renderer_data.renderer);
}

void Window::handle_event(const SDL_Event *event) {
    switch (event->type) {
    case SDL_EVENT_WINDOW_RESIZED:
        Clay_SetLayoutDimensions((Clay_Dimensions){(float)event->window.data1, (float)event->window.data2});
        break;
    case SDL_EVENT_MOUSE_MOTION:
        Clay_SetPointerState((Clay_Vector2){event->motion.x, event->motion.y}, event->motion.state & SDL_BUTTON_LMASK);
        break;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
        Clay_SetPointerState((Clay_Vector2){event->button.x, event->button.y}, event->button.button == SDL_BUTTON_LEFT);
        break;
    case SDL_EVENT_MOUSE_WHEEL:
        Clay_UpdateScrollContainers(true, (Clay_Vector2){event->wheel.x, event->wheel.y}, 0.01f);
        break;
    }
}

uint32_t Window::get_id() {
    return SDL_GetWindowID(window);
}
