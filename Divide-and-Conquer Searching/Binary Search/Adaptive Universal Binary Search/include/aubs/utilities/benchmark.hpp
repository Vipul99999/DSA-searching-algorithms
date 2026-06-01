#ifndef AUBS_UTILITIES_BENCHMARK_HPP
#define AUBS_UTILITIES_BENCHMARK_HPP

#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "timer.hpp"

namespace aubs::utilities {

struct BenchmarkResult
{
    std::string name;

    double averageNs = 0.0;

    double minNs = 0.0;

    double maxNs = 0.0;

    std::size_t iterations = 0;
};

class Benchmark
{
public:

    template<typename Function>
    static BenchmarkResult run(
        const std::string& name,
        Function&& function,
        std::size_t iterations = 1000
    )
    {
        BenchmarkResult result;

        result.name = name;
        result.iterations = iterations;

        std::vector<double> samples;
        samples.reserve(iterations);

        for(std::size_t i = 0;
            i < iterations;
            ++i)
        {
            Timer timer;

            function();

            samples.push_back(
                timer.elapsedNanoseconds()
            );
        }

        result.minNs =
            *std::min_element(
                samples.begin(),
                samples.end()
            );

        result.maxNs =
            *std::max_element(
                samples.begin(),
                samples.end()
            );

        result.averageNs =
            std::accumulate(
                samples.begin(),
                samples.end(),
                0.0
            ) / static_cast<double>(iterations);

        return result;
    }

    static void print(
        const BenchmarkResult& result
    )
    {
        std::cout
            << "\nBenchmark: "
            << result.name
            << '\n';

        std::cout
            << "Iterations : "
            << result.iterations
            << '\n';

        std::cout
            << "Average(ns): "
            << result.averageNs
            << '\n';

        std::cout
            << "Min(ns)    : "
            << result.minNs
            << '\n';

        std::cout
            << "Max(ns)    : "
            << result.maxNs
            << '\n';
    }
};

}

#endif