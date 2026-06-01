#ifndef AUBS_BENCHMARK_TIMER_HPP
#define AUBS_BENCHMARK_TIMER_HPP

#include <chrono>

namespace aubs::benchmark {

class BenchmarkTimer
{
public:

    using clock =
        std::chrono::high_resolution_clock;

    using time_point =
        clock::time_point;

private:

    time_point start_;
    time_point end_;

public:

    void start()
    {
        start_ = clock::now();
    }

    void stop()
    {
        end_ = clock::now();
    }

    [[nodiscard]]
    long long nanoseconds() const
    {
        return std::chrono::duration_cast<
            std::chrono::nanoseconds
        >(end_ - start_).count();
    }

    [[nodiscard]]
    double microseconds() const
    {
        return nanoseconds() / 1000.0;
    }

    [[nodiscard]]
    double milliseconds() const
    {
        return nanoseconds() / 1000000.0;
    }
};

}

#endif