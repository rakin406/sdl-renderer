cmake_minimum_required(VERSION 3.11)
project(avoid-me)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fstack-protector-all")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fdelete-null-pointer-checks")

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Use conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/main.cpp src/entityManager.cpp
    src/playerSystem.cpp src/window.cpp src/utils.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()
