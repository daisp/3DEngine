//
// Created by dais on 5/12/19.
//


#include "../headers/GraphicsEngine.h"

#include <chrono>
#include <thread>

GraphicsEngine::GraphicsEngine(const int &fps) : fps(fps), meshes(make_unique<Meshes>()),
                                                 renderer(make_unique<Renderer>()) {
}

GraphicsEngine::GraphicsEngine(const Meshes &meshes, const int &fps) :
        fps(fps), meshes(make_unique<Meshes>(meshes)), renderer(make_unique<Renderer>()) {
}


void GraphicsEngine::run() {
    meshes->push_back(Mesh::pyramid());
    while (true) {
        // TODO render each frame (busy wait with delay() as a start) using this->renderer.renderFrame()

        // update meshes
        for (auto &mesh : *meshes) {
            mesh.rotateCCWAroundYAxisRadiansInplace(0.04f);
        }

        renderer->renderFrame(*meshes);
        std::this_thread::sleep_for(std::chrono::milliseconds(18));
    }

}

