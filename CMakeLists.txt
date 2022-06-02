cmake_minimum_required(VERSION 3.22.1)


set(PROJECT_NAME 3D-Ray-Tracer)
set(CMAKE_CXX_STANDARD 17)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX) 


set(This Renderer)

add_subdirectory(googletest)


enable_testing()

set(HEADERS 
    src/tuples.h
    src/canvas.h
    src/matrix.h
    src/ray.h
)

set(SOURCES 
    src/tuples.cpp
    src/canvas.cpp
    src/matrix.cpp
    src/ray.cpp
    
)

add_library(${This} STATIC ${SOURCES} ${HEADERS})
target_compile_features( ${This} PUBLIC cxx_std_17)
add_subdirectory(tests)