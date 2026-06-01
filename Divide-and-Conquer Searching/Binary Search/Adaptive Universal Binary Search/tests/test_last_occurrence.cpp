#include <cassert>
#include <vector>

#include "../include/last_occurrence_policy.hpp"

using namespace aubs;

void testLastOccurrence()
{
    std::vector<int> data =
    {
        5,5,5,5,5
    };

    auto result =
        lastOccurrenceSearch(
            data.begin(),
            data.end(),
            5
        );

    assert(result.found());
    assert(result.index == 4);
}