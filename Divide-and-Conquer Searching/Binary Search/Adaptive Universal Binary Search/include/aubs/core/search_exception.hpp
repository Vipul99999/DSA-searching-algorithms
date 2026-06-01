#ifndef AUBS_SEARCH_EXCEPTION_HPP
#define AUBS_SEARCH_EXCEPTION_HPP

#include <stdexcept>

namespace aubs {

class SearchException
    : public std::runtime_error
{
public:

    explicit SearchException(
        const std::string& message
    )
        : std::runtime_error(
            message
        )
    {
    }
};

}

#endif