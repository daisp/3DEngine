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
include CMakeFiles/3DEngine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3DEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3DEngine.dir/flags.make

CMakeFiles/3DEngine.dir/source/main.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/main.cpp.o: ../source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3DEngine.dir/source/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/main.cpp.o -c /home/dais/CLionProjects/3DEngine/source/main.cpp

CMakeFiles/3DEngine.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/main.cpp > CMakeFiles/3DEngine.dir/source/main.cpp.i

CMakeFiles/3DEngine.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/main.cpp -o CMakeFiles/3DEngine.dir/source/main.cpp.s

CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o: ../source/GraphicsEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o -c /home/dais/CLionProjects/3DEngine/source/GraphicsEngine.cpp

CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/GraphicsEngine.cpp > CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.i

CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/GraphicsEngine.cpp -o CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.s

CMakeFiles/3DEngine.dir/source/Renderer.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/Renderer.cpp.o: ../source/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/3DEngine.dir/source/Renderer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/Renderer.cpp.o -c /home/dais/CLionProjects/3DEngine/source/Renderer.cpp

CMakeFiles/3DEngine.dir/source/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/Renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/Renderer.cpp > CMakeFiles/3DEngine.dir/source/Renderer.cpp.i

CMakeFiles/3DEngine.dir/source/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/Renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/Renderer.cpp -o CMakeFiles/3DEngine.dir/source/Renderer.cpp.s

CMakeFiles/3DEngine.dir/source/Mesh.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/Mesh.cpp.o: ../source/Mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/3DEngine.dir/source/Mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/Mesh.cpp.o -c /home/dais/CLionProjects/3DEngine/source/Mesh.cpp

CMakeFiles/3DEngine.dir/source/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/Mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/Mesh.cpp > CMakeFiles/3DEngine.dir/source/Mesh.cpp.i

CMakeFiles/3DEngine.dir/source/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/Mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/Mesh.cpp -o CMakeFiles/3DEngine.dir/source/Mesh.cpp.s

CMakeFiles/3DEngine.dir/source/Matrix.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/Matrix.cpp.o: ../source/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/3DEngine.dir/source/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/Matrix.cpp.o -c /home/dais/CLionProjects/3DEngine/source/Matrix.cpp

CMakeFiles/3DEngine.dir/source/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/Matrix.cpp > CMakeFiles/3DEngine.dir/source/Matrix.cpp.i

CMakeFiles/3DEngine.dir/source/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/Matrix.cpp -o CMakeFiles/3DEngine.dir/source/Matrix.cpp.s

CMakeFiles/3DEngine.dir/source/Triangle.cpp.o: CMakeFiles/3DEngine.dir/flags.make
CMakeFiles/3DEngine.dir/source/Triangle.cpp.o: ../source/Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/3DEngine.dir/source/Triangle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DEngine.dir/source/Triangle.cpp.o -c /home/dais/CLionProjects/3DEngine/source/Triangle.cpp

CMakeFiles/3DEngine.dir/source/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DEngine.dir/source/Triangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dais/CLionProjects/3DEngine/source/Triangle.cpp > CMakeFiles/3DEngine.dir/source/Triangle.cpp.i

CMakeFiles/3DEngine.dir/source/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DEngine.dir/source/Triangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dais/CLionProjects/3DEngine/source/Triangle.cpp -o CMakeFiles/3DEngine.dir/source/Triangle.cpp.s

# Object files for target 3DEngine
3DEngine_OBJECTS = \
"CMakeFiles/3DEngine.dir/source/main.cpp.o" \
"CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o" \
"CMakeFiles/3DEngine.dir/source/Renderer.cpp.o" \
"CMakeFiles/3DEngine.dir/source/Mesh.cpp.o" \
"CMakeFiles/3DEngine.dir/source/Matrix.cpp.o" \
"CMakeFiles/3DEngine.dir/source/Triangle.cpp.o"

# External object files for target 3DEngine
3DEngine_EXTERNAL_OBJECTS =

3DEngine: CMakeFiles/3DEngine.dir/source/main.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/source/GraphicsEngine.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/source/Renderer.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/source/Mesh.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/source/Matrix.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/source/Triangle.cpp.o
3DEngine: CMakeFiles/3DEngine.dir/build.make
3DEngine: CMakeFiles/3DEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable 3DEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3DEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3DEngine.dir/build: 3DEngine

.PHONY : CMakeFiles/3DEngine.dir/build

CMakeFiles/3DEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3DEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3DEngine.dir/clean

CMakeFiles/3DEngine.dir/depend:
	cd /home/dais/CLionProjects/3DEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dais/CLionProjects/3DEngine /home/dais/CLionProjects/3DEngine /home/dais/CLionProjects/3DEngine/cmake-build-debug /home/dais/CLionProjects/3DEngine/cmake-build-debug /home/dais/CLionProjects/3DEngine/cmake-build-debug/CMakeFiles/3DEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3DEngine.dir/depend
