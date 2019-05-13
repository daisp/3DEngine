//
// Created by dais on 5/12/19.
//

#include <thread>
#include <condition_variable>
#include <mutex>

#include "../headers/GraphicsEngine.h"

GraphicsEngine::GraphicsEngine() : dg(new int(DETECT)), gm(new int()), empty_string(new char(0)) {

    // gm is Graphics mode which is a computer display
    // mode that generates image using pixels.
    // initgraph initializes the graphics system
    // by loading a graphics driver from disk
    initgraph(this->dg, this->gm, this->empty_string);

    this->screen_width = getmaxx();
    this->screen_height = getmaxy();
}

GraphicsEngine::~GraphicsEngine() {

    // closegraph function closes the graphics
    // mode and deallocates all memory allocated
    // by graphics system.
    closegraph();

    // pointer member deallocation
    delete this->dg;
    delete this->gm;
    delete this->empty_string;
}

void GraphicsEngine::DrawLine(int x1, int y1, int x2, int y2) const {
    line(x1, y1, x2, y2);
}
