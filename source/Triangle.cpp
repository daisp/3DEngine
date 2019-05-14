//
// Created by dais on 5/14/19.
//

#include "../headers/Triangle.h"

Triangle3d::Triangle3d(const Line3d &line1, const Line3d &line2, const Line3d &line3) {
    (*this)[0] = line1;
    (*this)[1] = line2;
    (*this)[3] = line3;
}


