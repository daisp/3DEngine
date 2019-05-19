//
// Created by dais on 5/13/19.
//

#include "../headers/Mesh.h"
#include "../headers/Matrix.h"

Mesh Mesh::pyramid() {
    Mesh pyramid;

    // bottom (southeast)
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1, 0, -1), Vec3d(1, 0, 1)),
                                 Line3d(Vec3d(1, 0, 1), Vec3d(1, 0, -1)),
                                 Line3d(Vec3d(1, 0, -1), Vec3d(-1, 0, -1))));

    // bottom (northwest)
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1, 0, -1), Vec3d(-1, 0, 1)),
                                 Line3d(Vec3d(-1, 0, 1), Vec3d(1, 0, 1)),
                                 Line3d(Vec3d(1, 0, 1), Vec3d(-1, 0, -1))));

    // south
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1, 0, -1), Vec3d(0, 2, 0)),
                                 Line3d(Vec3d(0, 2, 0), Vec3d(1, 0, -1)),
                                 Line3d(Vec3d(1, 0, -1), Vec3d(-1, 0, -1))));

    // west
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1, 0, 1), Vec3d(0, 2, 0)),
                                 Line3d(Vec3d(0, 2, 0), Vec3d(-1, 0, -1)),
                                 Line3d(Vec3d(-1, 0, -1), Vec3d(-1, 0, 1))));

    // north
    pyramid.push_back(Triangle3d(Line3d(Vec3d(-1, 0, 1), Vec3d(0, 2, 0)),
                                 Line3d(Vec3d(0, 2, 0), Vec3d(1, 0, 1)),
                                 Line3d(Vec3d(1, 0, 1), Vec3d(-1, 0, 1))));

    // east
    pyramid.push_back(Triangle3d(Line3d(Vec3d(1, 0, 1), Vec3d(1, 0, -1)),
                                 Line3d(Vec3d(1, 0, -1), Vec3d(0, 2, 0)),
                                 Line3d(Vec3d(0, 2, 0), Vec3d(1, 0, 1))));

    return pyramid;
}

void Mesh::rotateCCWAroundYAxisRadiansInplace(float y_theta) {
    Matrix3x3Data rotation_matrix_data{
            Vec3d{cos(y_theta),0.0f,-sin(y_theta)},
            Vec3d{0.0f, 1.0f, 0.0f},
            Vec3d{sin(y_theta),0.0f, cos(y_theta)}
    };
    Matrix3x3 rotation_matrix(rotation_matrix_data);
    for (auto &triangle: *this){
        triangle.rotateCCWAroundYAxisRadiansInplace(rotation_matrix);
    }
}
