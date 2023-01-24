# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /goinfre/lsohler/.brew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /goinfre/lsohler/.brew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lsohler/pushswap/push_swap_visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lsohler/pushswap/push_swap_visualizer/build

# Include any dependencies generated for this target.
include src/CMakeFiles/visualizer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/visualizer.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/visualizer.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/visualizer.dir/flags.make

src/CMakeFiles/visualizer.dir/main.cpp.o: src/CMakeFiles/visualizer.dir/flags.make
src/CMakeFiles/visualizer.dir/main.cpp.o: /Users/lsohler/pushswap/push_swap_visualizer/src/main.cpp
src/CMakeFiles/visualizer.dir/main.cpp.o: src/CMakeFiles/visualizer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lsohler/pushswap/push_swap_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/visualizer.dir/main.cpp.o"
	cd /Users/lsohler/pushswap/push_swap_visualizer/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/visualizer.dir/main.cpp.o -MF CMakeFiles/visualizer.dir/main.cpp.o.d -o CMakeFiles/visualizer.dir/main.cpp.o -c /Users/lsohler/pushswap/push_swap_visualizer/src/main.cpp

src/CMakeFiles/visualizer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/visualizer.dir/main.cpp.i"
	cd /Users/lsohler/pushswap/push_swap_visualizer/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lsohler/pushswap/push_swap_visualizer/src/main.cpp > CMakeFiles/visualizer.dir/main.cpp.i

src/CMakeFiles/visualizer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/visualizer.dir/main.cpp.s"
	cd /Users/lsohler/pushswap/push_swap_visualizer/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lsohler/pushswap/push_swap_visualizer/src/main.cpp -o CMakeFiles/visualizer.dir/main.cpp.s

# Object files for target visualizer
visualizer_OBJECTS = \
"CMakeFiles/visualizer.dir/main.cpp.o"

# External object files for target visualizer
visualizer_EXTERNAL_OBJECTS =

bin/visualizer: src/CMakeFiles/visualizer.dir/main.cpp.o
bin/visualizer: src/CMakeFiles/visualizer.dir/build.make
bin/visualizer: src/libVisualizerLib.a
bin/visualizer: _deps/imgui-sfml-build/libImGui-SFML.a
bin/visualizer: _deps/sfml-build/lib/libsfml-graphics.2.5.1.dylib
bin/visualizer: _deps/sfml-build/lib/libsfml-window.2.5.1.dylib
bin/visualizer: _deps/sfml-build/lib/libsfml-system.2.5.1.dylib
bin/visualizer: src/CMakeFiles/visualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lsohler/pushswap/push_swap_visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/visualizer"
	cd /Users/lsohler/pushswap/push_swap_visualizer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/visualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/visualizer.dir/build: bin/visualizer
.PHONY : src/CMakeFiles/visualizer.dir/build

src/CMakeFiles/visualizer.dir/clean:
	cd /Users/lsohler/pushswap/push_swap_visualizer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/visualizer.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/visualizer.dir/clean

src/CMakeFiles/visualizer.dir/depend:
	cd /Users/lsohler/pushswap/push_swap_visualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lsohler/pushswap/push_swap_visualizer /Users/lsohler/pushswap/push_swap_visualizer/src /Users/lsohler/pushswap/push_swap_visualizer/build /Users/lsohler/pushswap/push_swap_visualizer/build/src /Users/lsohler/pushswap/push_swap_visualizer/build/src/CMakeFiles/visualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/visualizer.dir/depend

