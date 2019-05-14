//
// Created by dais on 5/13/19.
//

#include "../headers/Matrix.h"


Vec3d Matrix3x3::operator*(const Vec3d &v) const {
    return Vec3d(this->data[0].dot(v), this->data[1].dot(v), this->data[2].dot(v));
}

Matrix3x3::Matrix3x3(const Matrix3x3Data &data) : data(data) {}
