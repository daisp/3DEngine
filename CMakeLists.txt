cmake_minimum_required(VERSION 3.14)
project(3DEngine)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_LIBRARIES -lgraph)


add_executable(3DEngine source/main.cpp source/GraphicsEngine.cpp
        headers/Vec3D.h headers/Triangle.h source/Mesh.cpp headers/Mesh.h)

