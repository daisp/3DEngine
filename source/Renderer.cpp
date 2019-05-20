//
// Created by dais on 5/13/19.
//
#include "../headers/Renderer.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"

Renderer::Renderer(float z_near, float z_far, float fov_deg, Vec3d camera_location)
        : dg(new int(DETECT)), gm(new int()), empty_str(new char(0)), z_near(z_near), z_far(z_far),
          fov_deg(), fov_rad(fov_deg * 0.0174533), camera_location(camera_location),
          lines2d_to_render(make_unique<Lines2d>()) {
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
    this->aspect_ratio = static_cast<float>(screen_height) /
                         static_cast<float>(screen_width);
    this->f = 1 / tan(fov_rad / 2);
    this->q = z_far / (z_far - z_near);

    Matrix3x3Data projection_matrix_data = this->createProjectionMatrixData();
    this->projection_matrix = make_unique<Matrix3x3>(projection_matrix_data);
}


Matrix3x3Data Renderer::createProjectionMatrixData() const {
    // Mathematical explanation and meaning for variables here:
    // https://youtu.be/ih20l3pJoeU?t=1500

    Matrix3x3Data data;

    data[0].x = aspect_ratio * f;
    data[1].y = f;
    data[2].z = q;
    data[0].y = data[0].z = data[1].x = data[1].z = data[2].x = data[2].y = 0.0f;
    return data;
}


void Renderer::renderFrame(const Meshes &meshes) {
    this->clearLines2dToRender();
    this->projectMeshes(meshes);
    this->renderProjectedLines2d();
}

Line2d Renderer::projectLine3d(const Line3d &line_to_project) const {

    Line3d translated_line(line_to_project); // making a copy since line_to_project is const

    // flip horizontally and vertically
    translated_line.first = -translated_line.first;
    translated_line.second = -translated_line.second;

    // translate in relation to camera
    translated_line.first -= camera_location;
    translated_line.second -= camera_location;

    Line3d projected_3d_line(*(this->projection_matrix) * translated_line.first,
                             *(this->projection_matrix) * translated_line.second);
    projected_3d_line.first.z -= this->z_near * this->q;
    projected_3d_line.second.z -= this->z_near * this->q;

    float first_z = projected_3d_line.first.z;
    float second_z = projected_3d_line.second.z;
    if (first_z != 0.0f) {
        projected_3d_line.first.x /= first_z;
        projected_3d_line.first.y /= first_z;
    }
    if (second_z != 0.0f) {
        projected_3d_line.second.x /= second_z;
        projected_3d_line.second.y /= second_z;
    }


    // scale into view
    projected_3d_line.first.x += 1.0f;
    projected_3d_line.first.y += 1.0f;
    projected_3d_line.first.z += 1.0f;

    projected_3d_line.second.x += 1.0f;
    projected_3d_line.second.y += 1.0f;
    projected_3d_line.second.z += 1.0f;

    projected_3d_line.first.x *= 0.5f * screen_width;
    projected_3d_line.first.y *= 0.5f * screen_height;

    projected_3d_line.second.x *= 0.5f * screen_width;
    projected_3d_line.second.y *= 0.5f * screen_height;

    Vec2d first_projected(projected_3d_line.first.x, projected_3d_line.first.y);
    Vec2d second_projected(projected_3d_line.second.x, projected_3d_line.second.y);

    return Line2d{first_projected, second_projected};
}

void Renderer::renderLine2d(const Line2d &line_to_draw) const {
    line(static_cast<int>(line_to_draw.first.x),
         static_cast<int >(line_to_draw.first.y),
         static_cast<int>(line_to_draw.second.x),
         static_cast<int>(line_to_draw.second.y));
}

void Renderer::clearScreen() const {
    cleardevice();
}

void Renderer::projectMeshes(const Meshes &meshes_to_project) {
    for (auto &mesh_to_project : meshes_to_project)
        this->projectLines2dOfMesh(mesh_to_project);
}

void Renderer::projectLines2dOfMesh(const Mesh &mesh_to_project) {
    for (auto &triangle_to_project : mesh_to_project)
        this->projectLines2dOfTriangle3d(triangle_to_project);
}

void Renderer::projectLines2dOfTriangle3d(const Triangle3d &triangle_to_project) {
    for (auto &line_to_project: triangle_to_project)
        this->lines2d_to_render->push_back(this->projectLine3d(line_to_project));
}

void Renderer::renderProjectedLines2d() {
    this->clearScreen();
    for (auto &line_to_render : *lines2d_to_render) {
        renderLine2d(line_to_render);
    }
}

void Renderer::clearLines2dToRender() {
    this->lines2d_to_render->clear();
}






