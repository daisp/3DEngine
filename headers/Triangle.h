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
    explicit Triangle3d() = delete;

    Triangle3d(const Triangle3d &) = default;

    Triangle3d(const Line3d &line1, const Line3d &line2, const Line3d &line3);


    ~Triangle3d() = default;

    Triangle3d &operator=(const Triangle3d &) = default;


    bool operator==(const Triangle3d &rhs);

    bool operator!=(const Triangle3d &rhs);

    class Triangle3dException : public std::exception {
    };

    class LinesDontFormTriangleException : public Triangle3dException {
    public:
        explicit LinesDontFormTriangleException() : message("The Line3d argument provided are "
                                                            "do not form a valid 3D triangle.") {}

        const char *what() const noexcept override {
            return this->message.c_str();
        }

    private:
        std::string message;
    };
};


#endif //INC_3DENGINE_TRIANGLE_H
