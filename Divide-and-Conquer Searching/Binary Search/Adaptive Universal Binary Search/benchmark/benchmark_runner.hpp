#ifndef AUBS_BENCHMARK_RUNNER_HPP
#define AUBS_BENCHMARK_RUNNER_HPP

#include "benchmark_timer.hpp"
#include "benchmark_result.hpp"

namespace aubs::benchmark {

class BenchmarkRunner
{
public:

    template<
        typename Function
    >
    static BenchmarkResult run(
        const std::string& name,
        std::size_t datasetSize,
        std::size_t runs,
        Function function
    )
    {
        BenchmarkTimer timer;

        timer.start();

        for(std::size_t i = 0;
            i < runs;
            ++i)
        {
            function();
        }

        timer.stop();

        BenchmarkResult result;

        result.algorithm =
            name;

        result.datasetSize =
            datasetSize;

        result.totalNanoseconds =
            timer.nanoseconds();

        result.averageNanoseconds =
            static_cast<double>(
                result.totalNanoseconds
            ) / runs;

        result.throughput =
            runs /
            (
                result.totalNanoseconds
                / 1000000000.0
            );

        return result;
    }
};

}

#endif