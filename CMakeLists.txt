cmake_minimum_required(VERSION 3.11)
project(sdl-renderer)

cmake_policy(SET CMP0054 NEW)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fstack-protector-all")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fdelete-null-pointer-checks")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add dependencies
include(cmake/CPM.cmake)
CPMAddPackage(
    NAME SDL
    GITHUB_REPOSITORY libsdl-org/SDL
    GIT_TAG release-2.24.0
    VERSION 2.24.0
)

add_executable(example examples/example.cpp)
target_include_directories(example PRIVATE include)
target_link_libraries(example SDL2main SDL2)

if (MSVC)
    # Warning level 4 and warnings as errors
    add_compile_options(/W4 /Wx)
else()
    # Lots of warnings and warnings as errors
    add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror)
endif()
