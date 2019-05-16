//
// Created by dais on 5/14/19.
//

#include "../../headers/Vec.h"
#include "TestRunner.h"

FILE_GLOBAL_INIT;


void test_ctor_dtor() {
    Vec3d vec3d;
    ASSERT_TRUE(vec3d.x == 0.0 && vec3d.y == 0.0 && vec3d.z == 0.0);
//    ASSERT_FALSE(true);
//    ASSERT_TRUE(false);
}

void another_test() {
//    ASSERT_TRUE(false);
}

void third_test() {
}


int main(int argc, char **argv) {
    MAIN_FUNC_INIT(true);
    RUN_TEST(test_ctor_dtor)
    RUN_TEST(another_test);
    RUN_TEST(third_test);
    END_TESTS;
    return 0;
}
