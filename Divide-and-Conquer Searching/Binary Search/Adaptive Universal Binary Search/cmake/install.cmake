include(
    GNUInstallDirs
)

message(
    STATUS
    "Installing AUBS..."
)

install(
    DIRECTORY
    ${PROJECT_SOURCE_DIR}/include/
    DESTINATION
    ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT
    AUBSTargets
    FILE
    AUBSTargets.cmake
    NAMESPACE
    AUBS::
    DESTINATION
    ${CMAKE_INSTALL_LIBDIR}/cmake/AUBS
)