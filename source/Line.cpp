//
// Created by dais on 5/19/19.
//

#include "../headers/Line.h"

void Line3d::rotateCCWAroundYAxisRadiansInplace(const Matrix3x3 &rotation_matrix) {
    this->first = rotation_matrix * this->first;
    this->second = rotation_matrix * this->second;
}

Line3d::Line3d(Vec3d v1, Vec3d v2) : pair<Vec3d, Vec3d>(v1, v2) {}

Line2d::Line2d(Vec2d v1, Vec2d v2) : pair<Vec2d, Vec2d>(v1, v2) {}
