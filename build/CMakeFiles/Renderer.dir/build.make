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
include CMakeFiles/Renderer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Renderer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Renderer.dir/flags.make

CMakeFiles/Renderer.dir/src/tuples.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/tuples.cpp.o: ../src/tuples.cpp
CMakeFiles/Renderer.dir/src/tuples.cpp.o: CMakeFiles/Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Renderer.dir/src/tuples.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Renderer.dir/src/tuples.cpp.o -MF CMakeFiles/Renderer.dir/src/tuples.cpp.o.d -o CMakeFiles/Renderer.dir/src/tuples.cpp.o -c /Users/arnav25/Desktop/3D_Renderer/src/tuples.cpp

CMakeFiles/Renderer.dir/src/tuples.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/tuples.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnav25/Desktop/3D_Renderer/src/tuples.cpp > CMakeFiles/Renderer.dir/src/tuples.cpp.i

CMakeFiles/Renderer.dir/src/tuples.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/tuples.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnav25/Desktop/3D_Renderer/src/tuples.cpp -o CMakeFiles/Renderer.dir/src/tuples.cpp.s

CMakeFiles/Renderer.dir/src/canvas.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/canvas.cpp.o: ../src/canvas.cpp
CMakeFiles/Renderer.dir/src/canvas.cpp.o: CMakeFiles/Renderer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Renderer.dir/src/canvas.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Renderer.dir/src/canvas.cpp.o -MF CMakeFiles/Renderer.dir/src/canvas.cpp.o.d -o CMakeFiles/Renderer.dir/src/canvas.cpp.o -c /Users/arnav25/Desktop/3D_Renderer/src/canvas.cpp

CMakeFiles/Renderer.dir/src/canvas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/canvas.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnav25/Desktop/3D_Renderer/src/canvas.cpp > CMakeFiles/Renderer.dir/src/canvas.cpp.i

CMakeFiles/Renderer.dir/src/canvas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/canvas.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnav25/Desktop/3D_Renderer/src/canvas.cpp -o CMakeFiles/Renderer.dir/src/canvas.cpp.s

# Object files for target Renderer
Renderer_OBJECTS = \
"CMakeFiles/Renderer.dir/src/tuples.cpp.o" \
"CMakeFiles/Renderer.dir/src/canvas.cpp.o"

# External object files for target Renderer
Renderer_EXTERNAL_OBJECTS =

libRenderer.a: CMakeFiles/Renderer.dir/src/tuples.cpp.o
libRenderer.a: CMakeFiles/Renderer.dir/src/canvas.cpp.o
libRenderer.a: CMakeFiles/Renderer.dir/build.make
libRenderer.a: CMakeFiles/Renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libRenderer.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Renderer.dir/build: libRenderer.a
.PHONY : CMakeFiles/Renderer.dir/build

CMakeFiles/Renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Renderer.dir/clean

CMakeFiles/Renderer.dir/depend:
	cd /Users/arnav25/Desktop/3D_Renderer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arnav25/Desktop/3D_Renderer /Users/arnav25/Desktop/3D_Renderer /Users/arnav25/Desktop/3D_Renderer/build /Users/arnav25/Desktop/3D_Renderer/build /Users/arnav25/Desktop/3D_Renderer/build/CMakeFiles/Renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Renderer.dir/depend
