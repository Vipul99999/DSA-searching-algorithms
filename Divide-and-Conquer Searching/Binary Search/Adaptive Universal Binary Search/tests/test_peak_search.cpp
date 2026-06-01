#include <cassert>
#include <vector>

#include "../include/peak_search_policy.hpp"

using namespace aubs;

void testPeakSearch()
{
    std::vector<int> data =
    {
        1,3,20,4,1
    };

    auto result =
        peakSearch<
            std::vector<int>::iterator,
            int
        >(
            data.begin(),
            data.end()
        );

    assert(result.found());
    assert(result.index == 2);
}