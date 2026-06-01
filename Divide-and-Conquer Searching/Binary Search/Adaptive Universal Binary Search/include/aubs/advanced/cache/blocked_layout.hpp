#ifndef AUBS_BLOCKED_LAYOUT_HPP
#define AUBS_BLOCKED_LAYOUT_HPP

#include <vector>
#include <cstddef>

namespace aubs::cache {

template<
    typename T,
    std::size_t BlockSize = 64
>
class BlockedLayout
{
private:

    std::vector<T> blocks_;

public:

    BlockedLayout() = default;

    explicit BlockedLayout(
        const std::vector<T>& sortedData
    )
    {
        build(sortedData);
    }

    void build(
        const std::vector<T>& sortedData
    )
    {
        blocks_.clear();

        const std::size_t n =
            sortedData.size();

        for(std::size_t block = 0;
            block < n;
            block += BlockSize)
        {
            const std::size_t end =
                std::min(
                    block + BlockSize,
                    n
                );

            for(std::size_t i = block;
                i < end;
                ++i)
            {
                blocks_.push_back(
                    sortedData[i]
                );
            }
        }
    }

    [[nodiscard]]
    const std::vector<T>&
    data() const noexcept
    {
        return blocks_;
    }

    [[nodiscard]]
    std::size_t size() const noexcept
    {
        return blocks_.size();
    }
};

}

#endif