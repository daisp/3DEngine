//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_VEC_H
#define INC_3DENGINE_VEC_H

#include <array>


class Vec3d {
public:
    float x, y, z;

    explicit Vec3d() : x(0.0f), y(0.0f), z(0.0f) {}

    explicit Vec3d(float x, float y, float z) : x(x), y(y), z(z) {}

    explicit Vec3d(int x, int y, int z) : x(static_cast<float>(x)),
                                          y(static_cast<float>(y)),
                                          z(static_cast<float>(z)) {}

    explicit Vec3d(double x, double y, double z) : x(static_cast<float>(x)),
                                                   y(static_cast<float>(y)),
                                                   z(static_cast<float>(z)) {}

    explicit Vec3d(const char x, const char y, const char z) = delete;

    bool operator==(const Vec3d &rhs) const {
        return (x == rhs.x && y == rhs.y && z == rhs.z);
    }

    bool operator!=(const Vec3d &rhs) const { return !(*this == rhs); }

    Vec3d(const Vec3d &v) = default;

    ~Vec3d() = default;

    float dot(const Vec3d &v) const {
        return (x * v.x + y * v.y + z * v.z);
    }

    Vec3d &operator=(const Vec3d rhs) {
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        return *this;
    }

    void operator+=(const Vec3d &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
    }

    void operator-=(const Vec3d &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
    }

    Vec3d &operator-() {
        x = -x;
        y = -y;
        z = -z;
        return *this;
    }

    // some common 3D vectors
    static const Vec3d zero() { return Vec3d(0.0f, 0.0f, 0.0f); }

    static const Vec3d up() { return Vec3d(0.0f, 1.0f, 0.0f); }

    static const Vec3d down() { return Vec3d(0.0f, -1.0f, 0.0f); }

    static const Vec3d north() { return Vec3d(0.0f, 0.0f, 1.0f); }

    static const Vec3d south() { return Vec3d(0.0f, 0.0f, -1.0f); }

    static const Vec3d east() { return Vec3d(1.0f, 0.0f, 0.0f); }

    static const Vec3d west() { return Vec3d(-1.0f, 0.0f, 0.0f); }
};


class Vec2d {
public:
    float x, y;

    explicit Vec2d() : x(0.0), y(0.0) {}

    Vec2d(float x, float y) : x(x), y(y) {}

    Vec2d(const Vec2d &v) = default;

    ~Vec2d() = default;

    bool operator==(const Vec2d &rhs) {
        return (this->x == rhs.x && this->y == rhs.y);
    }

    bool operator!=(const Vec2d &rhs) {
        return (!(*this == rhs));
    }

    // some common 2D vectors
    static const Vec2d zero() { return Vec2d(0.0, 0.0); }

    static const Vec2d up() { return Vec2d(0.0, 1.0); }

    static const Vec2d down() { return Vec2d(0.0, -1.0); }

    static const Vec2d left() { return Vec2d(-1.0, 0.0); }

    static const Vec2d right() { return Vec2d(1.0, 0.0); }
};


#endif //INC_3DENGINE_VEC_H
