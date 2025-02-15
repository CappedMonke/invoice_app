#pragma once

#include <map>
#include <memory>

union SDL_Event;
class SDL_Window;
class SDL_Renderer;
class Window;

class Window_manager {
public:
    static Window_manager &get_instance();

    void start_up();
    void shut_down();
    void update();
    void handle_event(const SDL_Event *event);

    template <typename Window_class>
    void open_window();

    void close_window(Window *window);
    void close_window_by_id(uint32_t window_id);
    void close_all_windows();

private:
    uint32_t active_window_id = 0;
    std::map<uint32_t, Window *> windows;
};