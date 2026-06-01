#ifndef AUBS_BENCHMARK_COMPARISON_HPP
#define AUBS_BENCHMARK_COMPARISON_HPP

#include <vector>
#include <algorithm>

#include "benchmark_result.hpp"

namespace aubs::benchmark {

class BenchmarkComparison
{
public:

    static void sortBySpeed(
        std::vector<BenchmarkResult>& results
    )
    {
        std::sort(
            results.begin(),
            results.end(),
            [](const auto& a,
               const auto& b)
            {
                return
                    a.averageNanoseconds
                    <
                    b.averageNanoseconds;
            }
        );
    }
};

}

#endif