#ifndef AUBS_UTILITIES_TIMER_HPP
#define AUBS_UTILITIES_TIMER_HPP

#include <chrono>

namespace aubs::utilities {

class Timer
{
public:

    using Clock =
        std::chrono::high_resolution_clock;

    using TimePoint =
        Clock::time_point;

    Timer()
    {
        reset();
    }

    void reset()
    {
        start_ = Clock::now();
    }

    [[nodiscard]]
    double elapsedNanoseconds() const
    {
        return std::chrono::duration<double, std::nano>(
            Clock::now() - start_
        ).count();
    }

    [[nodiscard]]
    double elapsedMicroseconds() const
    {
        return std::chrono::duration<double, std::micro>(
            Clock::now() - start_
        ).count();
    }

    [[nodiscard]]
    double elapsedMilliseconds() const
    {
        return std::chrono::duration<double, std::milli>(
            Clock::now() - start_
        ).count();
    }

    [[nodiscard]]
    double elapsedSeconds() const
    {
        return std::chrono::duration<double>(
            Clock::now() - start_
        ).count();
    }

private:

    TimePoint start_;
};

}

#endif