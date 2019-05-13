//
// Created by dais on 5/13/19.
//
#include "../headers/Renderer.h"
#include <cassert>

void test_smoke(const Renderer &r) {
    assert(r.screen_height > 0 && r.screen_width > 0);

    Lines2d lines_to_render;
    r.renderFrame(lines_to_render);
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-integer-division"
void test_simple_line_rendering(const Renderer &r) {
    Lines2d lines_to_render;

    // lines of length 0
    lines_to_render.push_back(Line2d(Vec2d(r.screen_width, r.screen_height),
                                     Vec2d(r.screen_width, r.screen_height)));
    getch();
    r.renderFrame(lines_to_render);
    lines_to_render.push_back(Line2d(Vec2d(0, 0), Vec2d(0, 0)));
    getch();
    r.renderFrame(lines_to_render);
    lines_to_render.push_back(Line2d(Vec2d(r.screen_width / 2, r.screen_height / 2),
                                     Vec2d(r.screen_width / 2, r.screen_height / 2)));
    getch();
    r.renderFrame(lines_to_render);

    // fullscreen diagonal lines
    lines_to_render.push_back(Line2d(Vec2d(0, 0), Vec2d(r.screen_width, r.screen_height)));
    lines_to_render.push_back(Line2d(Vec2d(r.screen_width, 0), Vec2d(0, r.screen_height)));
    r.renderFrame(lines_to_render);
    getch();
}
#pragma clang diagnostic pop

void test_simple_animation(const Renderer &r) {
    auto animation_len = 400;
    Lines2d lines_to_render;
    lines_to_render.push_back(Line2d(Vec2d(0,0),Vec2d(50,50)));
    for (auto i = 0; i < animation_len; ++i) {
        lines_to_render[0].first.x++;
        lines_to_render[0].first.y++;
        lines_to_render[0].second.x++;
        lines_to_render[0].second.y++;
        r.renderFrame(lines_to_render);
        delay(2);
    }
}

int main() {
    Renderer r;
    test_smoke(r);
//    test_simple_line_rendering(r);
    test_simple_animation(r);
}
