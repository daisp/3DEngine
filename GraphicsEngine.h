//
// Created by dais on 5/12/19.
//

#ifndef INC_3DENGINE_GRAPHICSENGINE_H
#define INC_3DENGINE_GRAPHICSENGINE_H

#include <graphics.h>
#include <memory>

using std::unique_ptr;
using std::make_unique;

class GraphicsEngine {
private:
    int *dg;
    int *gm;
    char *empty_string;

public:
    explicit GraphicsEngine();

    ~GraphicsEngine();

    void DrawLine(int x1, int y1, int x2, int y2) const;
};


#endif //INC_3DENGINE_GRAPHICSENGINE_H
