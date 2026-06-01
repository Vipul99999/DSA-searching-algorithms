#include <iostream>
#include <vector>

#include "../include/aubs.hpp"

int main()
{
    std::vector<int> data;

    for(int i=0;i<1000000;++i)
    {
        data.push_back(i);
    }

    constexpr int target = 750000;

    auto result =
        aubs::exactSearch(
            data.begin(),
            data.end(),
            target
        );

    std::cout
        << result.index
        << '\n';
}