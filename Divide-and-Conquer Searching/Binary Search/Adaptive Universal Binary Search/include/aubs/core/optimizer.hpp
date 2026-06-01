#ifndef AUBS_OPTIMIZER_HPP
#define AUBS_OPTIMIZER_HPP

#include "execution_policy.hpp"

namespace aubs {

class SearchOptimizer
{
public:

    template<typename Container>
    static ExecutionPolicy
    choose(
        const Container& container
    )
    {
        const auto size =
            container.size();

        if(size < 1024)
        {
            return
                ExecutionPolicy::
                    Classical;
        }

        if(size < 100000)
        {
            return
                ExecutionPolicy::
                    Branchless;
        }

        return
            ExecutionPolicy::
                CacheAware;
    }
};

}

#endif