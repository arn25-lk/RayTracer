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
include tests/CMakeFiles/Tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/Tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Tests.dir/flags.make

tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o: tests/CMakeFiles/Tests.dir/flags.make
tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o: ../tests/CanvasTests.cpp
tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o: tests/CMakeFiles/Tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o -MF CMakeFiles/Tests.dir/CanvasTests.cpp.o.d -o CMakeFiles/Tests.dir/CanvasTests.cpp.o -c /Users/arnav25/Desktop/3D_Renderer/tests/CanvasTests.cpp

tests/CMakeFiles/Tests.dir/CanvasTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tests.dir/CanvasTests.cpp.i"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnav25/Desktop/3D_Renderer/tests/CanvasTests.cpp > CMakeFiles/Tests.dir/CanvasTests.cpp.i

tests/CMakeFiles/Tests.dir/CanvasTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tests.dir/CanvasTests.cpp.s"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnav25/Desktop/3D_Renderer/tests/CanvasTests.cpp -o CMakeFiles/Tests.dir/CanvasTests.cpp.s

# Object files for target Tests
Tests_OBJECTS = \
"CMakeFiles/Tests.dir/CanvasTests.cpp.o"

# External object files for target Tests
Tests_EXTERNAL_OBJECTS =

tests/Tests: tests/CMakeFiles/Tests.dir/CanvasTests.cpp.o
tests/Tests: tests/CMakeFiles/Tests.dir/build.make
tests/Tests: lib/libgtest_maind.a
tests/Tests: libRenderer.a
tests/Tests: lib/libgtestd.a
tests/Tests: tests/CMakeFiles/Tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tests"
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Tests.dir/build: tests/Tests
.PHONY : tests/CMakeFiles/Tests.dir/build

tests/CMakeFiles/Tests.dir/clean:
	cd /Users/arnav25/Desktop/3D_Renderer/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/Tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Tests.dir/clean

tests/CMakeFiles/Tests.dir/depend:
	cd /Users/arnav25/Desktop/3D_Renderer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arnav25/Desktop/3D_Renderer /Users/arnav25/Desktop/3D_Renderer/tests /Users/arnav25/Desktop/3D_Renderer/build /Users/arnav25/Desktop/3D_Renderer/build/tests /Users/arnav25/Desktop/3D_Renderer/build/tests/CMakeFiles/Tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Tests.dir/depend
