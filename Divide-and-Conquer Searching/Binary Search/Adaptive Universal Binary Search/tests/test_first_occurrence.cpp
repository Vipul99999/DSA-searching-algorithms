#include <cassert>
#include <vector>

#include "../include/first_occurrence_policy.hpp"

using namespace aubs;

void testFirstOccurrence()
{
    std::vector<int> data =
    {
        5,5,5,5,5
    };

    auto result =
        firstOccurrenceSearch(
            data.begin(),
            data.end(),
            5
        );

    assert(result.found());
    assert(result.index == 0);
}