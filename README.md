# SDL renderer

A simple header only library for creating windows and drawing shapes using SDL.

## Description

I started this repository as a game project... But failed with it. When I was
making the game, I also made the small header file for SDL windows and rendering
which I thought would be useful later in future. So I kept that in and abandoned
the game project and here we are :)

## Getting Started

### Dependencies

* GCC/Clang
* Conan
* CMake
* Ninja

### Installing

* Just download/copy/move the header file from include/ to your project.

### Executing examples

```bash
git clone https://github.com/rakin406/sdl-renderer.git && cd sdl-renderer
mkdir build && cd build
conan install .. --build=missing
cmake .. -G Ninja
ninja
./bin/example
```

## Author

Rakin Rahman

## License

This project is licensed under the MIT License - see the LICENSE.md file for details
