# 3D-Ray-Tracer

A simple 3D ray tracer implemented in C++ with support for linear algebra, reflection, and pixel-based rendering.  
Includes unit tests using [GoogleTest](https://github.com/google/googletest) and a clean build setup using CMake.

---

## Project Structure

3D-Ray-Tracer/

├── src/ # Core ray tracing logic (tuples, canvas, matrix, rays, reflection, etc.)

├── tests/ # Unit tests for the ray tracer

├── googletest/ # GoogleTest (included as a Git submodule)

├── CMakeLists.txt # Top-level CMake build script

└── build/ # (Generated at build time)

```bash
git clone --recurse-submodules https://github.com/your-username/RayTracer.git
cd RayTracer
```

## Build and Test

```bash
mkdir build
cd build
cmake ..
make
```
To run tests, go inside the `build` directory after building and run
```bash
ctest
```
or run individual tests

```bash
./tests/reflection_test
./tests/ray_test
```


## Features

Vector and matrix algebra (tuples, transformations)

Ray-object intersection

Reflection logic using Phong Reflection Model

Pixel canvas with PPM output support and exporting to .png handled by stbi

Unit-tested core components using GoogleTest


### Dependecies

C++17 or later

CMake ≥ 3.22

GoogleTest (included as a submodule)
