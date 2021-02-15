# Automate: Auto Animate

## Triple-A Methodology

Apply **A**ctions to **A**ctors to create **A**nimations

## Compiling from Source

### Dependencies

The following dependencies are required:
- C++ compiler that supports at least C++17
- `CMake` for building
- `GLFW` for the window display
- `Vulkan` for graphics rendering

Install [CMake](https://cmake.org/) and the C++ compiler if not already installed.

Follow this [Vulkan Setup Tutorial](https://vulkan-tutorial.com/Development_environment) to install the remaining dependencies for your OS. Only follow the package install steps as the environment setup is handled by CMake. Additional packages may be also required; follow relevant documentation to install them.

### Building

- For Debug builds use `cmake -DDebug=ON -S . -B build/debug/`
- For Release builds use `cmake -DDebug=OFF -S . -B build/release/`

Once the build files have been generated, use them with your build method (ie. makefile, VS, etc.) to compile the program.

