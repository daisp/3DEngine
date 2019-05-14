//
// Created by dais on 5/13/19.
//

#include "../headers/Mesh.h"

Mesh Mesh::pyramid() {
    Mesh pyramid;

    // bottom (southeast)
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1,0,-1), Vec3d(1,0,1)),
                                 Line3d(Vec3d(1,0,1), Vec3d(1,0,-1)),
                                 Line3d(Vec3d(1,0,-1), Vec3d(-1,0,-1))));

    // bottom (northwest)
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1,0,-1), Vec3d(-1,0,1)),
                                 Line3d(Vec3d(-1,0,1), Vec3d(1,0,1)),
                                 Line3d(Vec3d(1,0,1), Vec3d(-1,0,-1))));

    // south
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1,0,-1), Vec3d(0,0,1)),
                                 Line3d(Vec3d(0,0,1), Vec3d(1,0,-1)),
                                 Line3d(Vec3d(1,0,-1), Vec3d(-1,0,-1))));

    // west
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1,0,1), Vec3d(0,0,1)),
                                 Line3d(Vec3d(0,0,1), Vec3d(-1,0,-1)),
                                 Line3d(Vec3d(-1,0,-1), Vec3d(-1,0,1))));

    // north
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1,0,1), Vec3d(0,0,1)),
                                 Line3d(Vec3d(0,0,1), Vec3d(1,0,1)),
                                 Line3d(Vec3d(1,0,1), Vec3d(-1,0,1))));

    // east
    pyramid.push_back(Triangle3d(Line3d(Vec3d(1,0,1), Vec3d(1,0,-1)),
                                 Line3d(Vec3d(1,0,-1), Vec3d(0,0,1)),
                                 Line3d(Vec3d(0,0,1), Vec3d(1,0,1))));

    return pyramid;
}
