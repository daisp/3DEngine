//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_LINE_H
#define INC_3DENGINE_LINE_H

#include "Vec.h"
#include "Matrix.h"

using std::pair;

class Line2d : public pair<Vec2d, Vec2d> {
public:
    Line2d(Vec2d v1, Vec2d v2);
};

class Line3d : public pair<Vec3d, Vec3d> {
public:
    Line3d(Vec3d v1, Vec3d v2);

    void rotateCCWAroundYAxisRadiansInplace(const Matrix3x3 &rotation_matrix);
};

#endif //INC_3DENGINE_LINE_H
