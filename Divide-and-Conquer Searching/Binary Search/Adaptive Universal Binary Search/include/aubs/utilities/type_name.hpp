#ifndef AUBS_UTILITIES_TYPE_NAME_HPP
#define AUBS_UTILITIES_TYPE_NAME_HPP

#include <string>
#include <typeinfo>

#if defined(__GNUG__)
#include <cxxabi.h>
#include <cstdlib>
#endif

namespace aubs::utilities {

class TypeName
{
public:

    template<typename T>
    static std::string get()
    {
#if defined(__GNUG__)

        int status = 0;

        char* result =
            abi::__cxa_demangle(
                typeid(T).name(),
                nullptr,
                nullptr,
                &status
            );

        std::string name =
            (status == 0 && result)
            ? result
            : typeid(T).name();

        std::free(result);

        return name;

#else

        return typeid(T).name();

#endif
    }
};

}

#endif