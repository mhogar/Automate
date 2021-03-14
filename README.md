# Automate: Auto Animate

## Triple-A Methodology

Apply **A**ctions to **A**ctors to create **A**nimations

## Building and Installing

`Automate` is built using `CMake`.
- For Debug builds use `cmake -DDebug=ON -S . -B build/debug/`
- For Release builds use `cmake -DDebug=OFF -S . -B build/release/`

Change into the appropriate build directory and run `make`. This will create a shared library called `libautomate-core.so.x.y.z`, where x, y, and z are the major, minor, and patch versions respectively. Two symbolic links to the library called `libautomate-core.so.x` and `libautomate-core.so` will also be created.

(Optional) Run `sudo make install` to install the libraries and public header files (those in the `include` dir) to `usr/local/`.