//
// Created by dais on 5/13/19.
//

#ifndef INC_3DENGINE_RENDERER_H
#define INC_3DENGINE_RENDERER_H

// for multithreaded support
//#include <thread>
//#include <condition_variable>
//#include <mutex>
//#include <chrono>

#include <graphics.h>
#include <vector>

#include "Line.h"
#include "Mesh.h"

using std::vector;


//using std::thread;
//using std::condition_variable;
//using std::mutex;

//typedef vector<thread> Threads;
typedef vector<Line3d> Lines3d;
typedef vector<Line2d> Lines2d;

class Renderer {
private:
//    Threads renderer_threads;
//    mutex render_lock;
//    condition_variable render_cv;
//    bool is_render_possible;


    int *dg;
    int *gm;
    char *empty_string;


    void initializeRendererGraphics();

//    void initializeRendererMultithreading();

    void drawLine2d(const Line2d &line_to_draw) const;

public:
    Renderer();

    Renderer(const Renderer &renderer) = delete;

    ~Renderer();

    void operator=(const Renderer &renderer) = delete;

    void renderFrame(const Lines2d &lines_to_render) const;

    void clearScreen() const;

    int screen_width{};
    int screen_height{};
};


#endif //INC_3DENGINE_RENDERER_H
