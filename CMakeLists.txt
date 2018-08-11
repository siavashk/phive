set(_cmake_required_version 3.8.2)
if("${CMAKE_VERSION}" VERSION_LESS ${_cmake_required_version})
    message(FATAL_ERROR "You are running version ${CMAKE_VERSION} of CMake. Version ${_cmake_required_version} or higer is required.\n")
endif()

# Even though we perform a manual check above, so that we can output a custom message;
# CMake must execute this line since it sets CMAKE_MINIMUM_REQUIRED_VERSION
# which is required by many *.cmake scripts that CMake uses.
cmake_minimum_required(VERSION ${_cmake_required_version})

cmake_policy(SET CMP0012 NEW)
cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0043 NEW)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0058 NEW)
cmake_policy(SET CMP0063 NEW)

project(phive)

add_subdirectory(executables)