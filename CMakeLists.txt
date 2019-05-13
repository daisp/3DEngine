cmake_minimum_required(VERSION 3.14)
project(3DEngine)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_LIBRARIES -lgraph)
set(CMAKE_CXX_FLAGS -pthread)


add_executable(3DEngine source/main.cpp source/GraphicsEngine.cpp source/Renderer.cpp
        headers/Vec.h headers/Triangle.h source/Mesh.cpp headers/Mesh.h headers/Renderer.h headers/Line.h
        tests/test_Renderer.cpp source/Matrix.cpp headers/Matrix.h)

add_executable(test_Renderer source/Renderer.cpp tests/test_Renderer.cpp)
