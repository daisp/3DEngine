//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_MESH_H
#define INC_3DENGINE_MESH_H

#include <list>
#include <cmath>

#include "Triangle.h"


using std::list;
using std::sin;
using std::cos;

class Mesh : public list<Triangle3d> {
public:
    explicit Mesh() = default;

    Mesh(const Mesh &original_mesh)= default;

    ~Mesh() = default;

    void rotateCCWAroundYAxisRadiansInplace(float y_theta);

    static Mesh pyramid();
};

typedef list<Mesh> Meshes;

#endif //INC_3DENGINE_MESH_H
