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

    int *dg, *gm;
    char *empty_str;

    // projection-related members
    unique_ptr<Matrix3x3> projection_matrix;
    float z_near, z_far, fov_deg, fov_rad, aspect_ratio, f, q;
    Vec3d camera_location;

    void initializeRendererGraphics();

    Matrix3x3Data createProjectionMatrixData() const;

    void drawLine2d(const Line2d &line_to_draw) const;

    void renderMesh(const Mesh &mesh) const;

    void renderTriangle(const Triangle3d &triangle) const;

    Line2d projectLine(const Line3d &original_line) const;

public:
    int screen_width;
    int screen_height;

    explicit Renderer(float z_near = 0.5f, float z_far = 1000.0f, float fov_deg = 100.0f,
                      Vec3d camera_location = Vec3d(0.0f, -1.f, -4.0f));

    Renderer(const Renderer &renderer) = delete;

    ~Renderer();

    void operator=(const Renderer &renderer) = delete;

    void renderFrame(const Lines2d &lines_to_render) const;

    void renderFrame(const Meshes &meshes) const;

    void clearScreen() const;

};


#endif //INC_3DENGINE_RENDERER_H
