#ifndef AUBS_SEARCH_TRAITS_HPP
#define AUBS_SEARCH_TRAITS_HPP

#include <type_traits>

namespace aubs {

template<typename T>
struct SearchTraits
{
    static constexpr bool
    supportsSIMD =
        std::is_integral_v<T> ||
        std::is_floating_point_v<T>;

    static constexpr bool
    supportsBranchless =
        std::is_arithmetic_v<T>;

    static constexpr bool
    supportsPrediction =
        std::is_arithmetic_v<T>;
};

}

#endif