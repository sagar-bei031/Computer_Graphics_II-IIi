# COMPUTER GRAPHICS LAB BEI II/II

Codes written in SDL2 during Computer Graphics lab of BEI II/II in 2024 (2080 BS).

## Algorithms
1. Digital Differential ALgorithm
2. Bresenham's Line Drawing Algorithm
3. Mid-point Circle Drawing Algorithm
4. Mid-point Ellipse Drawing Algorithm
5. 2D-Transformation (Scaling, Translation, Rotation)
6. Cohen–Sutherland Line Clipping Algorithm

## How to use it?
I have provided files in `.hpp` and `.cpp` format. In order to use the algorithms, just include them `except main.cpp` and use the functions defined in these files in your own code. `main.cpp` is there as an `example file`.

## Build and Run
```bash
mkdir build # make build directory
cd build # Enter into build
cmake .. # Compile cmake files
make -j8 # build project
make run # run prokect
```

**Executable file is located at `build/src/` and name of the file is `graphics`**