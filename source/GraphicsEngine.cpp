//
// Created by dais on 5/12/19.
//


#include "../headers/GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(const int &fps) : fps(fps), meshes(make_unique<Meshes>()),
                                                 renderer(make_unique<Renderer>()) {
}

GraphicsEngine::GraphicsEngine(const Meshes &meshes, const int &fps) :
        fps(fps), meshes(make_unique<Meshes>(meshes)), renderer(make_unique<Renderer>()) {
}


void GraphicsEngine::run() {
    // TODO render each frame (busy wait with delay() as a start) using this->renderer.renderFrame()
}

