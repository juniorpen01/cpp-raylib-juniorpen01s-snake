# Build Instructions

This document outlines how to build and test the project.

## Prerequisites

* Python
* CMake
* A C++ compiler that supports C++23
* Ninja

## Getting Started

Clone the repository. This guide will also be using the build type **debug**. You can replace it with **release**.

```bash
git clone https://github.com/juniorpen01/cpp-raylib-juniorpen01s-snake
cd cpp-raylib-juniorpen01s-snake
```

## Building the Project

1. Check out the build script

    ```bash
    python build.py 
    ```

2. Generate build files

    ```bash
    python build.py generate debug
    ```

3. Build the project

    ```bash
    python build.py build debug
    ```

## Running the project

* You can call `./build/debug/juniorpen01s_snake`

    ```bash
    ./build/debug/juniorpen01s_snake
    ```

* Or better, use the build script that also rebuilds the project for you (you may need to regenerate, for example when deleting files)

    ```bash
    python build.py run release --exe juniorpen01s_snake
    ```

## Testing the project

Test using the build script

```bash
python build.py test debug
```

## Temporary

`
git clone https://github.com/juniorpen01/cpp-raylib-juniorpen01s-snake
cd cpp-raylib-juniorpen01s-snake
`

btw this shi doesnt work lmfao cuz of a bunch of windows.h and raylib conflicts
