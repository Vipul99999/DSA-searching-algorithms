#ifndef AUBS_BENCHMARK_REPORT_HPP
#define AUBS_BENCHMARK_REPORT_HPP

#include <iostream>
#include <iomanip>
#include "benchmark_result.hpp"

namespace aubs::benchmark {

class BenchmarkReport
{
public:

    static void print(
        const BenchmarkResult& result
    )
    {
        std::cout
            << "\n==============================\n";

        std::cout
            << "Algorithm     : "
            << result.algorithm
            << '\n';

        std::cout
            << "Dataset Size  : "
            << result.datasetSize
            << '\n';

        std::cout
            << "Iterations    : "
            << result.iterations
            << '\n';

        std::cout
            << "Comparisons   : "
            << result.comparisons
            << '\n';

        std::cout
            << "Branches      : "
            << result.branchCount
            << '\n';

        std::cout
            << "Average(ns)   : "
            << result.averageNanoseconds
            << '\n';

        std::cout
            << "Throughput    : "
            << result.throughput
            << '\n';

        std::cout
            << "==============================\n";
    }
};

}

#endif