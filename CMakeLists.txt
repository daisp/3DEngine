cmake_minimum_required(VERSION 3.14)
project(3DEngine)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_LIBRARIES -lgraph)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(3DEngine source/main.cpp source/GraphicsEngine.cpp source/Renderer.cpp
        headers/Vec.h headers/Triangle.h source/Mesh.cpp headers/Mesh.h headers/Renderer.h headers/Line.h
        source/Matrix.cpp headers/Matrix.h source/Triangle.cpp source/Line.cpp)

# Google Test integration. The following code is directly copied off of the official GitHub repo.

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. E.g.

# official Google Test code ends here. 3DEngine code follows

# Tests
# Vec
add_executable(test_Vec tests/gtest/test_Vec.cpp headers/Vec.h)
target_link_libraries(test_Vec gtest_main)

# Triangle
add_executable(test_Triangle tests/gtest/test_Triangle.cpp source/Triangle.cpp)
target_link_libraries(test_Triangle gtest_main)

add_test(NAME example_test COMMAND example)