//
// Created by dais on 5/13/19.
//
#include "../headers/Renderer.h"

Renderer::Renderer() : dg(new int(DETECT)), gm(new int()), empty_string(new char(0)) {
    initializeRendererGraphics();
//    initializeRendererMultithreading();
}


Renderer::~Renderer() {
    // closegraph() closes the graphics mode
    // and deallocates all memory allocated by the graphics system.
    closegraph();

    // raw pointer member deallocation
    delete this->dg;
    delete this->gm;
    delete this->empty_string;
}

void Renderer::initializeRendererGraphics() {
    // gm (graphics mode) is a computer display mode that generates an image using pixels.
    // initgraph() initializes the graphics system by loading a graphics driver from disk.
    initgraph(this->dg, this->gm, this->empty_string);

    this->screen_width = getmaxx();
    this->screen_height = getmaxy();
}


//void Renderer::initializeRendererMultithreading() {
//    // A Renderer class is initialized with a single renderer thread by default.
//    renderer_threads.push_back(thread(Renderer::renderFrame));
//}

void Renderer::renderFrame(const Lines2d &lines_to_render) const {
    this->clearScreen();
    for (auto line : lines_to_render) {
        this->drawLine2d(line);
    }
}

void Renderer::drawLine2d(const Line2d &line_to_draw) const {
    line(static_cast<int>(line_to_draw.first.x),
         static_cast<int >(line_to_draw.first.y),
         static_cast<int>(line_to_draw.second.x),
         static_cast<int>(line_to_draw.second.y));
}

void Renderer::clearScreen() const {
    cleardevice();
}


