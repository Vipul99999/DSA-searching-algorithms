#ifndef AUBS_SEARCH_RESULT_HPP
#define AUBS_SEARCH_RESULT_HPP

#include <optional>

#include "search_status.hpp"
#include "search_statistics.hpp"

namespace aubs {

template<typename T>
struct SearchResult
{
    SearchStatus status =
        SearchStatus::NotFound;

    std::size_t index = 0;

    std::optional<T> value;

    SearchStatistics statistics;

    [[nodiscard]]
    bool found() const noexcept
    {
        return status ==
               SearchStatus::Success;
    }
};

}

#endif