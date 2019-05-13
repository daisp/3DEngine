//
// Created by dais on 5/12/19.
//

#ifndef INC_3DENGINE_GRAPHICSENGINE_H
#define INC_3DENGINE_GRAPHICSENGINE_H

#include <graphics.h>
#include <memory>

// mathematical 3D float vector class (uses std::array API)
#include "../headers/Vec3D.h"

// each Triangle is composed of three Vec3D's (uses std::array API)
#include "../headers/Triangle.h"

// each mesh holds some amount of triangles
#include "../headers/Mesh.h"

using std::unique_ptr;
using std::make_unique;

class GraphicsEngine {
private:
    int *dg;
    int *gm;
    char *empty_string;
    int screen_width;
    int screen_height;

public:
    explicit GraphicsEngine();

    ~GraphicsEngine();

    void DrawLine(int x1, int y1, int x2, int y2) const;
};


#endif //INC_3DENGINE_GRAPHICSENGINE_H
