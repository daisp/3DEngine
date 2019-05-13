//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_MATRIX_H
#define INC_3DENGINE_MATRIX_H

#include <array>

#include "Vec.h"

using std::array;
typedef array<Vec3d, 3> Matrix3x3Data;


class Matrix3x3 {
public:
    Matrix3x3() = default;

    ~Matrix3x3() = default;

    Matrix3x3(const Matrix3x3 &mat) = default;

    Matrix3x3& operator=(const Matrix3x3 &rhs) = default;

    Vec3d operator*(const Vec3d &v) const;

private:
    Matrix3x3Data data;

};


#endif //INC_3DENGINE_MATRIX_H
