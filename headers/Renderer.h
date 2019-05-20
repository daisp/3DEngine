//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_RENDERER_H
#define INC_3DENGINE_RENDERER_H

#include <graphics.h>
#include <vector>
// for unique_ptr
#include <memory>

#include "Line.h"
#include "Mesh.h"
#include "Matrix.h"

using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::tan;

typedef vector<Line3d> Lines3d;
typedef vector<Line2d> Lines2d;

class Renderer {
private:

    // libgraph-related members
    int *dg, *gm;
    char *empty_str;
    int screen_width;
    int screen_height;

    // projection-related members
    unique_ptr<Matrix3x3> projection_matrix;
    float z_near, z_far, fov_deg, fov_rad, aspect_ratio, f, q;
    Vec3d camera_location;

    // line2d container holding the lines to render in the frame that's currently being constructed
    unique_ptr<Lines2d> lines2d_to_render;

    void initializeRendererGraphics();

    Matrix3x3Data createProjectionMatrixData() const;

    void clearLines2dToRender();

    void renderLine2d(const Line2d &line_to_draw) const;

    void renderProjectedLines2d();

    void projectMeshes(const Meshes &meshes_to_project);

    void projectLines2dOfMesh(const Mesh &mesh_to_project);

    Line2d projectLine3d(const Line3d &line_to_project) const;

    void projectLines2dOfTriangle3d(const Triangle3d &triangle_to_project);


public:
    explicit Renderer(float z_near = 0.5f, float z_far = 1000.0f, float fov_deg = 100.0f,
                      Vec3d camera_location = Vec3d(0.0f, -1.f, -4.0f));

    Renderer(const Renderer &renderer) = delete;

    ~Renderer();

    void operator=(const Renderer &renderer) = delete;

    void renderFrame(const Meshes &meshes);

    void clearScreen() const;

};


#endif //INC_3DENGINE_RENDERER_H
