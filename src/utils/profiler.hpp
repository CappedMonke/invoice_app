#pragma once

#include <chrono>

class Profiler {
public:
    Profiler(const char *name);
    ~Profiler();

private:
    const char *name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

#if NDEBUG
    #define PROFILE(name)
#else
    #define PROFILE(name) Profiler profiler(name)
#endif