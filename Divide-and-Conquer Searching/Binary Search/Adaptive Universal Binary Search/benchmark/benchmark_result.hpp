#ifndef AUBS_BENCHMARK_RESULT_HPP
#define AUBS_BENCHMARK_RESULT_HPP

#include <string>
#include <cstddef>

namespace aubs::benchmark {

struct BenchmarkResult
{
    std::string algorithm;

    std::size_t datasetSize = 0;

    long long totalNanoseconds = 0;

    double averageNanoseconds = 0.0;

    std::size_t iterations = 0;

    std::size_t comparisons = 0;

    std::size_t branchCount = 0;

    double throughput = 0.0;
};

}

#endif