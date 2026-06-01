cmake_minimum_required(VERSION 3.20)

project(
    AUBS
    VERSION 1.0.0
    DESCRIPTION "Adaptive Universal Binary Search Library"
    LANGUAGES CXX
)

###############################################################################
# Options
###############################################################################

option(
    AUBS_BUILD_TESTS
    "Build AUBS Tests"
    ON
)

option(
    AUBS_BUILD_BENCHMARKS
    "Build AUBS Benchmarks"
    ON
)

option(
    AUBS_ENABLE_WARNINGS
    "Enable Compiler Warnings"
    ON
)

###############################################################################
# C++ Standard
###############################################################################

set(
    CMAKE_CXX_STANDARD 20
)

set(
    CMAKE_CXX_STANDARD_REQUIRED ON
)

set(
    CMAKE_CXX_EXTENSIONS OFF
)

###############################################################################
# Library
###############################################################################

add_library(
    AUBS
    INTERFACE
)

target_include_directories(
    AUBS
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

###############################################################################
# Compiler Warnings
###############################################################################

if(AUBS_ENABLE_WARNINGS)

    if(MSVC)

        target_compile_options(
            AUBS
            INTERFACE
            /W4
        )

    else()

        target_compile_options(
            AUBS
            INTERFACE
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
        )

    endif()

endif()

###############################################################################
# Tests
###############################################################################

if(AUBS_BUILD_TESTS)

    enable_testing()

    add_executable(
        aubs_tests

        tests/test_suite.cpp

        tests/test_exact_search.cpp
        tests/test_lower_bound.cpp
        tests/test_upper_bound.cpp
        tests/test_first_occurrence.cpp
        tests/test_last_occurrence.cpp
        tests/test_search_insert.cpp
        tests/test_peak_search.cpp
        tests/test_rotated_search.cpp
        tests/test_exponential_search.cpp
        tests/test_binary_search_answer.cpp
    )

    target_link_libraries(
        aubs_tests
        PRIVATE
        AUBS
    )

    add_test(
        NAME AUBS_ALL_TESTS
        COMMAND aubs_tests
    )

endif()

###############################################################################
# Benchmarks
###############################################################################

if(AUBS_BUILD_BENCHMARKS)

    add_executable(
        aubs_benchmarks
        benchmarks/benchmark_main.cpp
    )

    target_link_libraries(
        aubs_benchmarks
        PRIVATE
        AUBS
    )

endif()

###############################################################################
# Install
###############################################################################

include(
    GNUInstallDirs
)

install(
    TARGETS AUBS
    EXPORT AUBSTargets
)

install(
    DIRECTORY include/
    DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT AUBSTargets
    FILE AUBSTargets.cmake
    NAMESPACE AUBS::
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/AUBS
)

include(
    CMakePackageConfigHelpers
)

configure_package_config_file(
    cmake/AUBSConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/AUBSConfig.cmake
    INSTALL_DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/AUBS
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/AUBSConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/AUBSConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/AUBSConfigVersion.cmake
    DESTINATION
        ${CMAKE_INSTALL_LIBDIR}/cmake/AUBS
)