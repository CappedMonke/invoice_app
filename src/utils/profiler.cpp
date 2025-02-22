#include "profiler.hpp"

#include <SDL3/SDL_log.h>

Profiler::Profiler(const char *name)
    : name(name) {
    start_time = std::chrono::high_resolution_clock::now();
}

Profiler::~Profiler() {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    SDL_Log("%s took %ld microseconds", name, duration.count());
}

void Profiler::lap(const char *name) {
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    SDL_Log("%s took %ld microseconds", name, duration.count());
    start_time = std::chrono::high_resolution_clock::now();
}
