//
// Created by dais on 5/12/19.
//

#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine() {

    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
    this->dg = new int(DETECT);
    this->gm = new int();

    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    this->empty_string = new char(0);
    initgraph(this->dg, this->gm, this->empty_string);

}

GraphicsEngine::~GraphicsEngine() {

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system.
    closegraph();
    delete this->dg;
    delete this->gm;
    delete this->empty_string;
}

void GraphicsEngine::DrawLine(int x1, int y1, int x2, int y2) const {
    line(x1, y1, x2, y2);
}
