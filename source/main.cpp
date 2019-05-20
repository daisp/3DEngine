#include "../headers/GraphicsEngine.h"

int main(int argc, char **argv) {
    Meshes meshes;
    meshes.push_back(Mesh::pyramid());

    GraphicsEngine engine;
    engine.addMultipleMeshes(meshes);
    engine.run();
    return 0;
}
