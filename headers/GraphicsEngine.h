//
// Created by dais on 5/12/19.
//

#ifndef INC_3DENGINE_GRAPHICSENGINE_H
#define INC_3DENGINE_GRAPHICSENGINE_H

#include <graphics.h>

// for unique_ptr
#include <memory>

// mathematical 3D float vector class (uses std::array API)
#include "Vec.h"

// each Triangle is composed of three Vec3D's (uses std::array API)
#include "../headers/Triangle.h"

// each mesh holds some amount of triangles
#include "../headers/Mesh.h"

// performs the actual screen drawing
#include "../headers/Renderer.h"


using std::unique_ptr;
using std::make_unique;

typedef list<Mesh> Meshes;

class GraphicsEngine {
public:
    explicit GraphicsEngine(const int &fps = 60);

    explicit GraphicsEngine(const Meshes &meshes, const int &fps = 60);

    GraphicsEngine(const GraphicsEngine &engine) = delete;

    void operator=(const GraphicsEngine &engine) = delete;

    ~GraphicsEngine() = default;

    void run();


private:

    unique_ptr<Meshes> meshes;
    unique_ptr<Renderer> renderer;
    int fps;

};


#endif //INC_3DENGINE_GRAPHICSENGINE_H
