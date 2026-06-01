#include <vector>

#include <lower_bound_policy.hpp>

int main()
{
    std::vector<int> data =
    {
        1,
        2,
        2,
        2,
        5
    };

    auto result =
        aubs::lowerBoundSearch(
            data.begin(),
            data.end(),
            2
        );
}