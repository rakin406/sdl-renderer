cmake_minimum_required(VERSION 3.11)
project(sdl-renderer)

cmake_policy(SET CMP0054 NEW)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS ${CMAKE_BUILD_TYPE})

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -pedantic -Werror")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Load module for speeding up builds
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(cotire)

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
cotire(example)
