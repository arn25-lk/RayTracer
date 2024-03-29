# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arnav25/Desktop/3D_Renderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arnav25/Desktop/3D_Renderer/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/ray_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/ray_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/ray_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/ray_test.dir/flags.make

tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o: tests/CMakeFiles/ray_test.dir/flags.make
tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o: ../tests/RaysTests.cpp
tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o: tests/CMakeFiles/ray_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o -MF CMakeFiles/ray_test.dir/RaysTests.cpp.o.d -o CMakeFiles/ray_test.dir/RaysTests.cpp.o -c /Users/arnav25/Desktop/3D_Renderer/tests/RaysTests.cpp

tests/CMakeFiles/ray_test.dir/RaysTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_test.dir/RaysTests.cpp.i"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnav25/Desktop/3D_Renderer/tests/RaysTests.cpp > CMakeFiles/ray_test.dir/RaysTests.cpp.i

tests/CMakeFiles/ray_test.dir/RaysTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_test.dir/RaysTests.cpp.s"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnav25/Desktop/3D_Renderer/tests/RaysTests.cpp -o CMakeFiles/ray_test.dir/RaysTests.cpp.s

# Object files for target ray_test
ray_test_OBJECTS = \
"CMakeFiles/ray_test.dir/RaysTests.cpp.o"

# External object files for target ray_test
ray_test_EXTERNAL_OBJECTS =

tests/ray_test: tests/CMakeFiles/ray_test.dir/RaysTests.cpp.o
tests/ray_test: tests/CMakeFiles/ray_test.dir/build.make
tests/ray_test: lib/libgtest_maind.a
tests/ray_test: libRenderer.a
tests/ray_test: lib/libgtestd.a
tests/ray_test: tests/CMakeFiles/ray_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ray_test"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/ray_test.dir/build: tests/ray_test
.PHONY : tests/CMakeFiles/ray_test.dir/build

tests/CMakeFiles/ray_test.dir/clean:
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/ray_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/ray_test.dir/clean

tests/CMakeFiles/ray_test.dir/depend:
	cd /Users/arnav25/Desktop/3D_Renderer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arnav25/Desktop/3D_Renderer /Users/arnav25/Desktop/3D_Renderer/tests /Users/arnav25/Desktop/3D_Renderer/build /Users/arnav25/Desktop/3D_Renderer/build/tests /Users/arnav25/Desktop/3D_Renderer/build/tests/CMakeFiles/ray_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/ray_test.dir/depend

