#ifndef AUBS_SEARCH_CONTEXT_HPP
#define AUBS_SEARCH_CONTEXT_HPP

namespace aubs {

struct SearchContext
{
    bool collectStatistics = true;

    bool enableSIMD = true;

    bool enableCacheAware =
        true;

    bool enableBranchless =
        true;

    bool enablePredictive =
        true;
};

}

#endif