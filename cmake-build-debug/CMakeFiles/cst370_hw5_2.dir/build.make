# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/justinmello/Documents/school/cst370/cst370_hw5_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cst370_hw5_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cst370_hw5_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cst370_hw5_2.dir/flags.make

CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o: CMakeFiles/cst370_hw5_2.dir/flags.make
CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o: ../hw5_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o -c /Users/justinmello/Documents/school/cst370/cst370_hw5_2/hw5_2.cpp

CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/justinmello/Documents/school/cst370/cst370_hw5_2/hw5_2.cpp > CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.i

CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/justinmello/Documents/school/cst370/cst370_hw5_2/hw5_2.cpp -o CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.s

# Object files for target cst370_hw5_2
cst370_hw5_2_OBJECTS = \
"CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o"

# External object files for target cst370_hw5_2
cst370_hw5_2_EXTERNAL_OBJECTS =

cst370_hw5_2: CMakeFiles/cst370_hw5_2.dir/hw5_2.cpp.o
cst370_hw5_2: CMakeFiles/cst370_hw5_2.dir/build.make
cst370_hw5_2: CMakeFiles/cst370_hw5_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cst370_hw5_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cst370_hw5_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cst370_hw5_2.dir/build: cst370_hw5_2

.PHONY : CMakeFiles/cst370_hw5_2.dir/build

CMakeFiles/cst370_hw5_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cst370_hw5_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cst370_hw5_2.dir/clean

CMakeFiles/cst370_hw5_2.dir/depend:
	cd /Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/justinmello/Documents/school/cst370/cst370_hw5_2 /Users/justinmello/Documents/school/cst370/cst370_hw5_2 /Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug /Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug /Users/justinmello/Documents/school/cst370/cst370_hw5_2/cmake-build-debug/CMakeFiles/cst370_hw5_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cst370_hw5_2.dir/depend

