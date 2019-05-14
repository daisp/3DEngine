//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_TRIANGLE_H
#define INC_3DENGINE_TRIANGLE_H

#include <array>

#include "Line.h"

using std::array;

class Triangle3d : public array<Line3d, 3> {
public:
    explicit Triangle3d() = default;
    Triangle3d(const Triangle3d&) = default;
    ~Triangle3d() = default;

    Triangle3d(const Line3d &line1, const Line3d &line2, const Line3d &line3);
};


#endif //INC_3DENGINE_TRIANGLE_H
