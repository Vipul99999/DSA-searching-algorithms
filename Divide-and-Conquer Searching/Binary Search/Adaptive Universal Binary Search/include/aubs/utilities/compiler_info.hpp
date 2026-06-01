#ifndef AUBS_UTILITIES_COMPILER_INFO_HPP
#define AUBS_UTILITIES_COMPILER_INFO_HPP

#include <string>

namespace aubs::utilities {

class CompilerInfo
{
public:

    [[nodiscard]]
    static std::string compilerName()
    {
#if defined(__clang__)
        return "Clang";
#elif defined(__GNUC__)
        return "GCC";
#elif defined(_MSC_VER)
        return "MSVC";
#else
        return "Unknown";
#endif
    }

    [[nodiscard]]
    static std::string compilerVersion()
    {
#if defined(__clang__)
        return
            std::to_string(__clang_major__) +
            "." +
            std::to_string(__clang_minor__);

#elif defined(__GNUC__)
        return
            std::to_string(__GNUC__) +
            "." +
            std::to_string(__GNUC_MINOR__);

#elif defined(_MSC_VER)
        return
            std::to_string(_MSC_VER);

#else
        return "Unknown";
#endif
    }

    [[nodiscard]]
    static std::string cppStandard()
    {
        return std::to_string(__cplusplus);
    }
};

}

#endif