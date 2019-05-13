//
// Created by dais on 5/13/19.
//

#include "../headers/Matrix.h"


Vec3d Matrix3x3::operator*(const Vec3d &v) const {
    Vec3d out;
    out.x = this->data[0].dot(v);
    out.y = this->data[1].dot(v);
    out.z = this->data[2].dot(v);
    return out;
}
