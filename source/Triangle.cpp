//
// Created by dais on 5/14/19.
//

#include "../headers/Triangle.h"

Triangle3d::Triangle3d(const Line3d &line1, const Line3d &line2, const Line3d &line3) :
        array<Line3d, 3>{line1, line2, line3} {
    if (line1.second != line2.first || line2.second != line3.first || line3.second != line1.first)
        throw LinesDontFormTriangleException();
}

bool Triangle3d::operator==(const Triangle3d &rhs) {
    return ((*this)[0] == rhs[0] && (*this)[1] == rhs[1] && (*this)[2] == rhs[2]);
}

bool Triangle3d::operator!=(const Triangle3d &rhs) {
    return !(*this == rhs);
}

void Triangle3d::rotateCCWAroundYAxisRadiansInplace(const Matrix3x3 &rotation_matrix) {
    for (auto &line : *this) {
        line.rotateCCWAroundYAxisRadiansInplace(rotation_matrix);
    }
}
