//
// Created by dais on 5/16/19.
//

#include <gtest/gtest.h>

#include "../../headers/Triangle.h"
#include <memory>
#include <limits>
#include <random>
#include <set>

using std::make_unique;
using std::unique_ptr;
using std::set;

const int REPETITIONS = 10000;
const float MAX_FLOAT = std::numeric_limits<float>::max();
const float MIN_FLOAT = std::numeric_limits<float>::min();

namespace {

    // The fixture for testing class Foo.
    class Triangle3dTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        Triangle3dTest() {
            // You can do set-up work for each test here.
        }

        ~Triangle3dTest() override {
            // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up
        // and cleaning up each test, you can define the following methods:

        void SetUp() override {
            // Code here will be called immediately after the constructor (right
            // before each test).
        }

        void TearDown() override {
            // Code here will be called immediately after each test (right
            // before the destructor).
        }

        // Objects declared here can be used by all tests in the test case
        // for your tested class.
    };

    const float getRandomFloat() {
        std::random_device rd;
        std::knuth_b random_generator_engine(rd());
        std::uniform_real_distribution<float> dist(-1000, 1000);
        auto random_float = dist(random_generator_engine);
        return random_float;
    }

    TEST_F(Triangle3dTest, ConstructsAndDestroys) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();
            float x3 = getRandomFloat(), y3 = getRandomFloat(), z3 = getRandomFloat();

            Line3d l1(Vec3d(x1, y1, z1), Vec3d(x2, y2, z2));
            Line3d l2(Vec3d(x2, y2, z2), Vec3d(x3, y3, z3));
            Line3d l3(Vec3d(x3, y3, z3), Vec3d(x1, y1, z1));

            // valid triangle
            ASSERT_NO_THROW(Triangle3d tri_no_throw(l1, l2, l3));

            // invalid triangle composed of 3 3D lines that do not start and end at the same point
            ASSERT_THROW(Triangle3d tri_throw1(l1, l2, l1),
                         Triangle3d::LinesDontFormTriangleException);
            ASSERT_THROW(Triangle3d tri_throw2(l2, l1, l3),
                         Triangle3d::LinesDontFormTriangleException);
        }
    }

    TEST_F(Triangle3dTest, InitialValuesCorrect) {    // NOLINT(cert-err58-cpp)
        // lines ctor
        Line3d l1, l2, l3;
        Triangle3d tri_lines_ctor(l1, l2, l3);
        EXPECT_EQ(tri_lines_ctor[0].first, Vec3d());
        EXPECT_EQ(tri_lines_ctor[0].second, Vec3d());

        EXPECT_EQ(tri_lines_ctor[1].first, Vec3d());
        EXPECT_EQ(tri_lines_ctor[1].second, Vec3d());

        EXPECT_EQ(tri_lines_ctor[2].first, Vec3d());
        EXPECT_EQ(tri_lines_ctor[2].second, Vec3d());

        // random fixed values ctor
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();
            float x3 = getRandomFloat(), y3 = getRandomFloat(), z3 = getRandomFloat();

            Line3d l4(Vec3d(x1, y1, z1), Vec3d(x2, y2, z2));
            Line3d l5(Vec3d(x2, y2, z2), Vec3d(x3, y3, z3));
            Line3d l6(Vec3d(x3, y3, z3), Vec3d(x1, y1, z1));

            auto tri_fixed_points = make_unique<Triangle3d>(l4, l5, l6);

            EXPECT_EQ((*tri_fixed_points)[0].first, Vec3d(x1, y1, z1));
            EXPECT_EQ((*tri_fixed_points)[0].second, Vec3d(x2, y2, z2));

            EXPECT_EQ((*tri_fixed_points)[1].first, Vec3d(x2, y2, z2));
            EXPECT_EQ((*tri_fixed_points)[1].second, Vec3d(x3, y3, z3));

            EXPECT_EQ((*tri_fixed_points)[2].first, Vec3d(x3, y3, z3));
            EXPECT_EQ((*tri_fixed_points)[2].second, Vec3d(x1, y1, z1));
        }
    }

    TEST_F(Triangle3dTest, ConstructsViaCopyCtor) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();
            float x3 = getRandomFloat(), y3 = getRandomFloat(), z3 = getRandomFloat();

            Line3d l1(Vec3d(x1, y1, z1), Vec3d(x2, y2, z2));
            Line3d l2(Vec3d(x2, y2, z2), Vec3d(x3, y3, z3));
            Line3d l3(Vec3d(x3, y3, z3), Vec3d(x1, y1, z1));

            Triangle3d tri_original(l1, l2, l3);

            // checking construction
            ASSERT_NO_THROW(auto tri_copy(tri_original));

            // checking value correctness
            auto tri_copy(tri_original);
            EXPECT_EQ(tri_copy[0].first, tri_original[0].first);
            EXPECT_EQ(tri_copy[0].second, tri_original[0].second);

            EXPECT_EQ(tri_copy[1].first, tri_original[1].first);
            EXPECT_EQ(tri_copy[1].second, tri_original[1].second);

            EXPECT_EQ(tri_copy[2].first, tri_original[2].first);
            EXPECT_EQ(tri_copy[2].second, tri_original[2].second);
        }
    }

    TEST_F(Triangle3dTest, AssignsViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();
            float x3 = getRandomFloat(), y3 = getRandomFloat(), z3 = getRandomFloat();

            float x4 = getRandomFloat(), y4 = getRandomFloat(), z4 = getRandomFloat();
            float x5 = getRandomFloat(), y5 = getRandomFloat(), z5 = getRandomFloat();
            float x6 = getRandomFloat(), y6 = getRandomFloat(), z6 = getRandomFloat();

            Line3d l1(Vec3d(x1, y1, z1), Vec3d(x2, y2, z2));
            Line3d l2(Vec3d(x2, y2, z2), Vec3d(x3, y3, z3));
            Line3d l3(Vec3d(x3, y3, z3), Vec3d(x1, y1, z1));

            Line3d l4(Vec3d(x4, y4, z4), Vec3d(x5, y5, z5));
            Line3d l5(Vec3d(x5, y5, z5), Vec3d(x6, y6, z6));
            Line3d l6(Vec3d(x6, y6, z6), Vec3d(x4, y4, z4));

            Triangle3d tri1(l1, l2, l3);
            Triangle3d tri2(l4, l5, l6);

            // sanity check
            EXPECT_NE(tri1[0].first, tri2[0].first);
            EXPECT_NE(tri1[0].second, tri2[0].second);
            EXPECT_NE(tri1[1].first, tri2[1].first);
            EXPECT_NE(tri1[1].second, tri2[1].second);
            EXPECT_NE(tri1[2].first, tri2[2].first);
            EXPECT_NE(tri1[2].second, tri2[2].second);

            // actual test
            tri2 = tri1;
            EXPECT_EQ(tri1[0].first, tri2[0].first);
            EXPECT_EQ(tri1[0].second, tri2[0].second);
            EXPECT_EQ(tri1[1].first, tri2[1].first);
            EXPECT_EQ(tri1[1].second, tri2[1].second);
            EXPECT_EQ(tri1[2].first, tri2[2].first);
            EXPECT_EQ(tri1[2].second, tri2[2].second);
        }
    }

    TEST_F(Triangle3dTest, ComparesByValueViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();
            float x3 = getRandomFloat(), y3 = getRandomFloat(), z3 = getRandomFloat();

            float x4 = getRandomFloat(), y4 = getRandomFloat(), z4 = getRandomFloat();
            float x5 = getRandomFloat(), y5 = getRandomFloat(), z5 = getRandomFloat();
            float x6 = getRandomFloat(), y6 = getRandomFloat(), z6 = getRandomFloat();

            Line3d l1(Vec3d(x1, y1, z1), Vec3d(x2, y2, z2));
            Line3d l2(Vec3d(x2, y2, z2), Vec3d(x3, y3, z3));
            Line3d l3(Vec3d(x3, y3, z3), Vec3d(x1, y1, z1));

            Line3d l4(Vec3d(x4, y4, z4), Vec3d(x5, y5, z5));
            Line3d l5(Vec3d(x5, y5, z5), Vec3d(x6, y6, z6));
            Line3d l6(Vec3d(x6, y6, z6), Vec3d(x4, y4, z4));

            // same triangles
            Triangle3d tri1(l1, l2, l3);
            Triangle3d tri2(l1, l2, l3);

            EXPECT_TRUE(tri1 == tri2);
            EXPECT_TRUE(tri2 == tri1);
            EXPECT_FALSE(tri1 != tri2);
            EXPECT_FALSE(tri2 != tri1);

//            // difference in a single Line3d
//            Triangle3d tri3(l1, l2, l6);
//            EXPECT_FALSE(tri3 == tri1);
//            EXPECT_FALSE(tri1 == tri3);
//            EXPECT_TRUE(tri3 != tri1);
//            EXPECT_TRUE(tri1 != tri3);
//
//            Triangle3d tri4(l1, l5, l3);
//            EXPECT_FALSE(tri4 == tri1);
//            EXPECT_FALSE(tri1 == tri4);
//            EXPECT_TRUE(tri4 != tri1);
//            EXPECT_TRUE(tri1 != tri4);
//
//            Triangle3d tri5(l4, l2, l3);
//            EXPECT_FALSE(tri5 == tri1);
//            EXPECT_FALSE(tri1 == tri5);
//            EXPECT_TRUE(tri5 != tri1);
//            EXPECT_TRUE(tri1 != tri5);
//
//            // difference in two Line3ds
//            Triangle3d tri6(l4, l5, l3);
//            EXPECT_FALSE(tri6 == tri1);
//            EXPECT_FALSE(tri1 == tri6);
//            EXPECT_TRUE(tri6 != tri1);
//            EXPECT_TRUE(tri1 != tri6);
//
//            Triangle3d tri7(l4, l2, l6);
//            EXPECT_FALSE(tri7 == tri1);
//            EXPECT_FALSE(tri1 == tri7);
//            EXPECT_TRUE(tri7 != tri1);
//            EXPECT_TRUE(tri1 != tri7);
//
//            Triangle3d tri8(l1, l5, l6);
//            EXPECT_FALSE(tri8 == tri1);
//            EXPECT_FALSE(tri1 == tri8);
//            EXPECT_TRUE(tri8 != tri1);
//            EXPECT_TRUE(tri1 != tri8);

            // difference in all 3 Line3ds
            Triangle3d tri9(l4, l5, l6);
            EXPECT_FALSE(tri9 == tri1);
            EXPECT_FALSE(tri1 == tri9);
            EXPECT_TRUE(tri9 != tri1);
            EXPECT_TRUE(tri1 != tri9);
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}