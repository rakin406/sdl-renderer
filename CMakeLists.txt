cmake_minimum_required(VERSION 3.11)
project(sdl-renderer)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(example examples/example.cpp)
target_include_directories(example PRIVATE include)
target_link_libraries(example ${CONAN_LIBS})
