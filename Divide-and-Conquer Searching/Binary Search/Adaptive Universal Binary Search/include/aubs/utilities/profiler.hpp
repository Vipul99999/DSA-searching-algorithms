#ifndef AUBS_UTILITIES_PROFILER_HPP
#define AUBS_UTILITIES_PROFILER_HPP

#include <iostream>
#include <string>

#include "timer.hpp"

namespace aubs::utilities {

class ScopedProfiler
{
public:

    explicit ScopedProfiler(
        std::string section
    )
        : section_(
            std::move(section)
        )
    {
    }

    ~ScopedProfiler()
    {
        std::cout
            << "[PROFILE] "
            << section_
            << " : "
            << timer_.elapsedMicroseconds()
            << " us\n";
    }

private:

    std::string section_;

    Timer timer_;
};

}

#endif