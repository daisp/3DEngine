//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_MESH_H
#define INC_3DENGINE_MESH_H

#include <list>

#include "Triangle.h"


using std::list;

class Mesh : public list<Triangle3d> {
public:
    explicit Mesh() = default;

    Mesh(const Mesh &original_mesh)= default;

    ~Mesh() = default;

    static Mesh pyramid();
};

typedef list<Mesh> Meshes;

#endif //INC_3DENGINE_MESH_H
