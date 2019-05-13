//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_VEC_H
#define INC_3DENGINE_VEC_H

#include <array>

class Vec3d {
public:
    float x, y, z;

    explicit Vec3d() : x(0.0), y(0.0), z(0.0) {}

    Vec3d(float x, float y, float z) : x(x), y(y), z(z) {}

    Vec3d(const Vec3d &v) = default;

    ~Vec3d() = default;

    // some common 3D vectors
    static const Vec3d zero() { return Vec3d(0.0, 0.0, 0.0); }

    static const Vec3d up() { return Vec3d(0.0, 1.0, 0.0); }

    static const Vec3d down() { return Vec3d(0.0, -1.0, 0.0); }

    static const Vec3d north() { return Vec3d(0.0, 0.0, 1.0); }

    static const Vec3d south() { return Vec3d(0.0, 0.0, -1.0); }

    static const Vec3d east() { return Vec3d(1.0, 0.0, 0.0); }

    static const Vec3d west() { return Vec3d(-1.0, 0.0, 0.0); }
};


class Vec2d {
public:
    float x, y;

    explicit Vec2d() : x(0.0), y(0.0) {}

    Vec2d(float x, float y) : x(x), y(y) {}

    Vec2d(const Vec2d &v) = default;

    ~Vec2d() = default;

    // some common 2D vectors
    static const Vec2d zero() { return Vec2d(0.0, 0.0); }

    static const Vec2d up() { return Vec2d(0.0, 1.0); }

    static const Vec2d down() { return Vec2d(0.0, -1.0); }

    static const Vec2d left() { return Vec2d(-1.0, 0.0); }

    static const Vec2d right() { return Vec2d(1.0, 0.0); }
};


#endif //INC_3DENGINE_VEC_H
