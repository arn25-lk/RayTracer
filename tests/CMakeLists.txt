cmake_minimum_required(VERSION 3.22.1)

target_compile_features( ${This} PUBLIC cxx_std_17)

set(This Tests)

add_executable(canvas_test CanvasTests.cpp)
add_executable(tuple_test TupleTests.cpp)
target_link_libraries(canvas_test PUBLIC 
    gtest_main
    Renderer)

target_link_libraries(tuple_test PUBLIC 
    gtest_main
    Renderer
)
add_test(
    NAME tuple_test
    COMMAND tuple_test
)
add_test(
    NAME canvas_test
    COMMAND canvas_test
)
