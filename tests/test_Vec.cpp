//
// Created by dais on 5/14/19.
//

#include "../headers/Vec.h"
#include "TestRunner.h"

void test_ctor_dtor() {
    Vec3d vec3d;
    assert(vec3d.x == 0.0 && vec3d.y == 0.0 && vec3d.z == 0.0);
}

int main(int argc, char **argv) {
    INIT_TESTS(true);
    RUN_TEST(test_ctor_dtor);
    END_TESTS;
    return 0;
}
