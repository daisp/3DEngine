# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /home/dais/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/dais/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/191.7141.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dais/CLionProjects/3DEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dais/CLionProjects/3DEngine/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_Line.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_Line.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_Line.dir/flags.make

CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o: CMakeFiles/test_Line.dir/flags.make
CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o: ../tests/gtest/test_Line.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o -c /home/dais/CLionProjects/3DEngine/tests/gtest/test_Line.cpp

CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/tests/gtest/test_Line.cpp > CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.i

CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/tests/gtest/test_Line.cpp -o CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.s

# Object files for target test_Line
test_Line_OBJECTS = \
"CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o"

# External object files for target test_Line
test_Line_EXTERNAL_OBJECTS =

test_Line: CMakeFiles/test_Line.dir/tests/gtest/test_Line.cpp.o
test_Line: CMakeFiles/test_Line.dir/build.make
test_Line: lib/libgtest_maind.a
test_Line: lib/libgtestd.a
test_Line: CMakeFiles/test_Line.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_Line"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_Line.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_Line.dir/build: test_Line

.PHONY : CMakeFiles/test_Line.dir/build

CMakeFiles/test_Line.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_Line.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_Line.dir/clean

CMakeFiles/test_Line.dir/depend:
	cd /home/dais/CLionProjects/3DEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dais/CLionProjects/3DEngine /home/dais/CLionProjects/3DEngine /home/dais/CLionProjects/3DEngine/cmake-build-debug /home/dais/CLionProjects/3DEngine/cmake-build-debug /home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles/test_Line.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_Line.dir/depend
