#ifndef AUBS_EXECUTION_POLICY_HPP
#define AUBS_EXECUTION_POLICY_HPP

namespace aubs {

enum class ExecutionPolicy
{
    Automatic,

    Classical,

    SIMD,

    CacheAware,

    Branchless,

    Predictive
};

}

#endif