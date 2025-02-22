#pragma once

#include <chrono>

class Profiler {
public:
    Profiler(const char *name);
    ~Profiler();

    void lap(const char *name);

private:
    const char *name;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

#if NDEBUG
    #define PROFILE(name)
    #define PROFILE_LAP(name)
#else
    #define PROFILE(name) Profiler profiler(name)
    #define PROFILE_LAP(name) profiler.lap(name)
#endif