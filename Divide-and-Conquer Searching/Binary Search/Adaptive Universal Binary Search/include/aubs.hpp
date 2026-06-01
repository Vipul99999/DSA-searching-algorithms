/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : aubs.hpp
 Version     : 1.0.0
 Author      : AUBS Research Project
 License     : MIT

 Description:
 ------------------------------------------------------------------------------
 Core foundation header for Adaptive Universal Binary Search (AUBS).

 This header provides:

 • Search Statistics
 • Search Result
 • Search Context
 • Search Modes
 • Search Policies
 • Binary Search Engine
 • Iterator Support
 • Generic Comparator Support
 • Predicate Support
 • Benchmark Hooks
 • Unit-Test Friendly Design

 All future search policies are built on top of this file.

===============================================================================
*/

#ifndef AUBS_HPP
#define AUBS_HPP

#include <algorithm>
#include <chrono>
#include <concepts>
#include <cstddef>
#include <functional>
#include <iterator>
#include <memory>
#include <optional>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace aubs {

/*
===============================================================================
 Version Information
===============================================================================
*/

inline constexpr const char* VERSION = "1.0.0";

/*
===============================================================================
 Search Mode
===============================================================================
*/

enum class SearchMode {
    ExactSearch,
    LowerBound,
    UpperBound,
    FirstOccurrence,
    LastOccurrence,
    SearchInsertPosition,
    PeakElement,
    RotatedArray,
    Exponential,
    BinarySearchAnswer,
    Custom
};

/*
===============================================================================
 Search Status
===============================================================================
*/

enum class SearchStatus {
    Success,
    NotFound,
    InvalidInput,
    Error
};

/*
===============================================================================
 Search Statistics
===============================================================================
*/

struct SearchStatistics {

    std::size_t iterations = 0;
    std::size_t comparisons = 0;
    std::size_t branchCount = 0;

    std::chrono::nanoseconds executionTime{0};

    void reset() {
        iterations = 0;
        comparisons = 0;
        branchCount = 0;
        executionTime = std::chrono::nanoseconds(0);
    }
};

/*
===============================================================================
 Search Result
===============================================================================
*/

template<typename T>
struct SearchResult {

    SearchStatus status = SearchStatus::NotFound;

    std::optional<T> value;

    std::size_t index = static_cast<std::size_t>(-1);

    SearchStatistics statistics;

    [[nodiscard]]
    bool found() const {
        return status == SearchStatus::Success;
    }
};

/*
===============================================================================
 Search Context
===============================================================================
*/

template<typename Comparator = std::less<>>
struct SearchContext {

    Comparator comparator{};

    bool enableStatistics = true;

    bool enableBenchmark = true;

    bool branchOptimized = false;

    bool cacheAware = false;
};

/*
===============================================================================
 Benchmark Hook Interface
===============================================================================
*/

class IBenchmarkHook {
public:

    virtual ~IBenchmarkHook() = default;

    virtual void onSearchStart() = 0;

    virtual void onSearchEnd(
        const SearchStatistics& stats
    ) = 0;
};

/*
===============================================================================
 Default Benchmark Hook
===============================================================================
*/

class NullBenchmarkHook final : public IBenchmarkHook {

public:

    void onSearchStart() override {}

    void onSearchEnd(
        const SearchStatistics&
    ) override {}
};

/*
===============================================================================
 Iterator Concept
===============================================================================
*/

template<typename Iterator>
concept RandomAccessIterator =
    std::random_access_iterator<Iterator>;

/*
===============================================================================
 Predicate Concept
===============================================================================
*/

template<typename Predicate, typename ValueType>
concept SearchPredicate =
    requires(Predicate p, ValueType value)
{
    { p(value) } -> std::convertible_to<bool>;
};

/*
===============================================================================
 Search Policy Interface
===============================================================================
*/

template<
    typename Iterator,
    typename ValueType
>
class ISearchPolicy {

public:

    virtual ~ISearchPolicy() = default;

    virtual SearchResult<ValueType> execute(
        Iterator begin,
        Iterator end,
        const ValueType& target
    ) = 0;
};

/*
===============================================================================
 Policy Pointer Alias
===============================================================================
*/

template<
    typename Iterator,
    typename ValueType
>
using PolicyPtr =
    std::unique_ptr<
        ISearchPolicy<
            Iterator,
            ValueType
        >
    >;

/*
===============================================================================
 Binary Search Engine
===============================================================================
*/

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class BinarySearchEngine {

public:

    using iterator_type = Iterator;
    using value_type = ValueType;
    using comparator_type = Comparator;

private:

    SearchContext<Comparator> context_;

    std::shared_ptr<IBenchmarkHook> benchmarkHook_;

public:

    explicit BinarySearchEngine(
        SearchContext<Comparator> context = {}
    )
        : context_(std::move(context)),
          benchmarkHook_(
              std::make_shared<NullBenchmarkHook>()
          ) {}

    void setBenchmarkHook(
        std::shared_ptr<IBenchmarkHook> hook
    ) {
        benchmarkHook_ = std::move(hook);
    }

    [[nodiscard]]
    const SearchContext<Comparator>& context() const {
        return context_;
    }

    template<typename Policy>
    SearchResult<ValueType> search(
        Iterator begin,
        Iterator end,
        const ValueType& target,
        Policy& policy
    )
    {
        benchmarkHook_->onSearchStart();

        auto start =
            std::chrono::high_resolution_clock::now();

        auto result =
            policy.execute(
                begin,
                end,
                target
            );

        auto finish =
            std::chrono::high_resolution_clock::now();

        result.statistics.executionTime =
            std::chrono::duration_cast<
                std::chrono::nanoseconds
            >(finish - start);

        benchmarkHook_->onSearchEnd(
            result.statistics
        );

        return result;
    }
};

/*
===============================================================================
 Generic Utility Functions
===============================================================================
*/

namespace utility {

/*
------------------------------------------------------------------------------
 Distance
------------------------------------------------------------------------------
*/

template<
    RandomAccessIterator Iterator
>
constexpr std::size_t distance(
    Iterator first,
    Iterator last
)
{
    return static_cast<std::size_t>(
        std::distance(first, last)
    );
}

/*
------------------------------------------------------------------------------
 Midpoint
------------------------------------------------------------------------------
*/

template<typename Integer>
constexpr Integer midpoint(
    Integer left,
    Integer right
)
{
    return left + (right - left) / 2;
}

/*
------------------------------------------------------------------------------
 Is Sorted
------------------------------------------------------------------------------
*/

template<
    RandomAccessIterator Iterator,
    typename Comparator = std::less<>
>
bool isSorted(
    Iterator begin,
    Iterator end,
    Comparator comp = Comparator{}
)
{
    return std::is_sorted(
        begin,
        end,
        comp
    );
}

} // namespace utility

/*
===============================================================================
 Predicate Search Base
===============================================================================
*/

template<
    typename Predicate,
    typename ValueType
>
requires SearchPredicate<
    Predicate,
    ValueType
>
class PredicateWrapper {

private:

    Predicate predicate_;

public:

    explicit PredicateWrapper(
        Predicate predicate
    )
        : predicate_(
            std::move(predicate)
        ) {}

    [[nodiscard]]
    bool operator()(
        const ValueType& value
    ) const
    {
        return predicate_(value);
    }
};

/*
===============================================================================
 Search Configuration
===============================================================================
*/

struct SearchConfiguration {

    bool enableStatistics = true;

    bool enableBenchmark = true;

    bool enableBranchOptimization = false;

    bool enableCacheOptimization = false;

    bool enablePrediction = false;
};

/*
===============================================================================
 Search Traits
===============================================================================
*/

template<typename T>
struct SearchTraits {

    using value_type = T;

    using reference = T&;

    using const_reference = const T&;
};

/*
===============================================================================
 Common Result Factories
===============================================================================
*/

template<typename T>
[[nodiscard]]
inline SearchResult<T>
makeSuccessResult(
    std::size_t index,
    const T& value
)
{
    SearchResult<T> result;

    result.status = SearchStatus::Success;
    result.index = index;
    result.value = value;

    return result;
}

template<typename T>
[[nodiscard]]
inline SearchResult<T>
makeNotFoundResult()
{
    SearchResult<T> result;

    result.status = SearchStatus::NotFound;

    return result;
}

template<typename T>
[[nodiscard]]
inline SearchResult<T>
makeErrorResult()
{
    SearchResult<T> result;

    result.status = SearchStatus::Error;

    return result;
}

/*
===============================================================================
 Future Extension Points
===============================================================================

Planned Components:

• ExactSearchPolicy
• LowerBoundPolicy
• UpperBoundPolicy
• FirstOccurrencePolicy
• LastOccurrencePolicy
• SearchInsertPolicy
• PeakElementPolicy
• RotatedArrayPolicy
• ExponentialSearchPolicy
• BinarySearchAnswerPolicy

• PredictiveSearchModule
• CacheAwareSearchModule
• BranchlessSearchModule
• SIMDSearchModule

===============================================================================
*/

} // namespace aubs

#endif // AUBS_HPP