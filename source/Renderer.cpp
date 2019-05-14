//
// Created by dais on 5/13/19.
//
#include "../headers/Renderer.h"

using std::tan;

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
Renderer::Renderer(float z_near, float z_far, float fov_deg)
        : dg(new int(DETECT)), gm(new int()), empty_str(new char(0)), z_near(z_near), z_far(z_far),
          fov_deg(), fov_rad(fov_deg * 0.0174533) {
    initializeRendererGraphics();
}
#pragma clang diagnostic pop


Renderer::~Renderer() {
    // closegraph() closes the graphics mode
    // and deallocates all memory allocated by the graphics system.
    closegraph();

    // raw pointer member deallocation
    delete this->dg;
    delete this->gm;
    delete this->empty_str;
}

void Renderer::initializeRendererGraphics() {
    // gm (graphics mode) is a computer display mode that generates an image using pixels.
    // initgraph() initializes the graphics system by loading a graphics driver from disk.
    initgraph(this->dg, this->gm, this->empty_str);

    this->screen_width = getmaxx();
    this->screen_height = getmaxy();
    this->aspect_ratio = static_cast<float>(this->screen_height) /
                         static_cast<float>(this->screen_width);

    Matrix3x3Data projection_matrix_data = this->createProjectionMatrixData();
    this->projection_matrix = make_unique<Matrix3x3>(projection_matrix_data);
}


Matrix3x3Data Renderer::createProjectionMatrixData() const {
    Matrix3x3Data data;
    data[0].x = aspect_ratio * (1 / tan(fov_rad / 2));
    data[1].y = 1 / tan(fov_rad / 2);
    data[2].z = this->z_far / (this->z_far - this->z_near);
    data[0].y = data[0].z = data[1].x = data[1].z = data[2].x = data[2].y = 0.0;
    return data;
}


void Renderer::renderFrame(const Lines2d &lines_to_render) const {
    this->clearScreen();
    for (auto &line : lines_to_render) {
        this->drawLine2d(line);
    }
}

void Renderer::renderFrame(const Meshes &meshes) const {
    for (auto &cur_mesh : meshes) {
        this->renderMesh(cur_mesh);
    }
}

void Renderer::renderMesh(const Mesh &mesh) const {
    for (auto &cur_triangle : mesh) {
        this->renderTriangle(cur_triangle);
    }
}

void Renderer::renderTriangle(const Triangle3d &triangle) const {
    for (const Line3d &line : triangle) {
        auto projected_line = this->projectLine(line);
        this->drawLine2d(projected_line);
    }
}

Line2d Renderer::projectLine(const Line3d &original_line) const {
    Line3d projected_3d_line(*(this->projection_matrix) * original_line.first,
                             *(this->projection_matrix) * original_line.second);
    Vec2d first_projected(projected_3d_line.first.x, projected_3d_line.first.y);
    Vec2d second_projected(projected_3d_line.second.x, projected_3d_line.second.y);
    return Line2d(first_projected, second_projected);
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





