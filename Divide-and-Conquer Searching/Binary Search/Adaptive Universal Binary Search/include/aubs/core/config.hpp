#ifndef AUBS_CONFIG_HPP
#define AUBS_CONFIG_HPP

namespace aubs {

struct Config
{
    bool enableSIMD = true;

    bool enableCacheAware =
        true;

    bool enableBranchless =
        true;

    bool enablePredictive =
        true;

    bool enableStatistics =
        true;
};

}

#endif