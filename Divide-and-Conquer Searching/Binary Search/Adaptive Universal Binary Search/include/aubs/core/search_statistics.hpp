#ifndef AUBS_SEARCH_STATISTICS_HPP
#define AUBS_SEARCH_STATISTICS_HPP

#include <cstddef>

namespace aubs {

struct SearchStatistics
{
    std::size_t iterations = 0;

    std::size_t comparisons = 0;

    std::size_t branchCount = 0;

    std::size_t cacheMisses = 0;

    std::size_t simdOperations = 0;
};

}

#endif