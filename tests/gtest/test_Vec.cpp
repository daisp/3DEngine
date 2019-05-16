//
// Created by dais on 5/16/19.
//

#include <gtest/gtest.h>

#include "../../headers/Vec.h"
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
    class Vec2dTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        Vec2dTest() {
            // You can do set-up work for each test here.
            int test_len = REPETITIONS;
        }

        ~Vec2dTest() override {
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

    TEST_F(Vec2dTest, ConstructsAndDestroys) {    // NOLINT(cert-err58-cpp)
        ASSERT_NO_THROW(auto v_default_ctor = make_unique<Vec2d>());
        ASSERT_NO_THROW(auto v_zeros_int = make_unique<Vec2d>(0, 0));
        ASSERT_NO_THROW(auto v_zeros_float = make_unique<Vec2d>(0.f, 0.f));
        ASSERT_NO_THROW(auto v_zeros_double = make_unique<Vec2d>(0., 0.));

        for (int i = 0; i < REPETITIONS; ++i)
            ASSERT_NO_THROW(auto v_random_floats = make_unique<Vec2d>(getRandomFloat(),
                                    getRandomFloat()));

    }

    TEST_F(Vec2dTest, InitialValuesCorrect) {    // NOLINT(cert-err58-cpp)
        auto v_zero = make_unique<Vec2d>();
        EXPECT_EQ(v_zero->x, 0.f);
        EXPECT_EQ(v_zero->y, 0.f);

        auto v_int = make_unique<Vec2d>(1, 2);
        EXPECT_EQ(v_int->x, 1.f);
        EXPECT_EQ(v_int->y, 2.f);

        auto v_float = make_unique<Vec2d>(1.f, 2.f);
        EXPECT_EQ(v_float->x, 1.f);
        EXPECT_EQ(v_float->y, 2.f);

        auto v_double = make_unique<Vec2d>(1.0, 2.0);
        EXPECT_EQ(v_double->x, 1.f);
        EXPECT_EQ(v_double->y, 2.f);

        for (int i = 0; i < REPETITIONS; ++i) {
            float x = getRandomFloat(), y = getRandomFloat();
            Vec2d v(x, y);
            ASSERT_EQ(v.x, x);
            ASSERT_EQ(v.y, y);
        }
    }

    TEST_F(Vec2dTest, ConstructsViaCopyCtor) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            // checking construction
            Vec2d v(getRandomFloat(), getRandomFloat());
            ASSERT_NO_THROW(auto v_copy(v));

            // checking value correctness
            auto v_copy(v);
            EXPECT_EQ(v.x, v_copy.x);
            EXPECT_EQ(v.y, v_copy.y);
        }
    }

    TEST_F(Vec2dTest, AssignsViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            Vec2d v1(getRandomFloat(), getRandomFloat());
            Vec2d v2;
            v2 = v1;
            EXPECT_EQ(v1.x, v2.x);
            EXPECT_EQ(v1.y, v2.y);
        }
    }

    TEST_F(Vec2dTest, ComparesByValueViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat();

            Vec2d v1(x1, y1), v2(x1, y1);
            EXPECT_TRUE(v2 == v1);
            EXPECT_TRUE(v1 == v2);
            EXPECT_FALSE(v2 != v1);
            EXPECT_FALSE(v1 != v2);

            Vec2d v3(x2, y1);
            EXPECT_FALSE(v1 == v3);
            EXPECT_FALSE(v3 == v1);
            EXPECT_TRUE(v1 != v3);
            EXPECT_TRUE(v3 != v1);

            Vec2d v4(x1, y2);
            EXPECT_FALSE(v1 == v4);
            EXPECT_FALSE(v4 == v1);

            Vec2d v5(x2, y2);
            EXPECT_FALSE(v1 == v5);
            EXPECT_FALSE(v5 == v1);
        }
    }


// The fixture for testing class Foo.
    class Vec3dTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body
        // is empty.

        Vec3dTest() {
            // You can do set-up work for each test here.
            int test_len = REPETITIONS;
        }

        ~Vec3dTest() override {
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

    TEST_F(Vec3dTest, ConstructsAndDestroys) {    // NOLINT(cert-err58-cpp)
        ASSERT_NO_THROW(auto v_default_ctor = make_unique<Vec3d>());
        ASSERT_NO_THROW(auto v_zeros_int = make_unique<Vec3d>(0, 0, 0));
        ASSERT_NO_THROW(auto v_zeros_float = make_unique<Vec3d>(0.f, 0.f, 0.f));
        ASSERT_NO_THROW(auto v_zeros_double = make_unique<Vec3d>(0., 0., 0.));

        for (int i = 0; i < REPETITIONS; ++i)
            ASSERT_NO_THROW(auto v_random_floats = make_unique<Vec3d>(getRandomFloat(),
                                    getRandomFloat(), getRandomFloat()));

    }

    TEST_F(Vec3dTest, InitialValuesCorrect) {    // NOLINT(cert-err58-cpp)
        auto v_zero = make_unique<Vec3d>();
        EXPECT_EQ(v_zero->x, 0.f);
        EXPECT_EQ(v_zero->y, 0.f);
        EXPECT_EQ(v_zero->z, 0.f);

        auto v_int = make_unique<Vec3d>(1, 2, 3);
        EXPECT_EQ(v_int->x, 1.f);
        EXPECT_EQ(v_int->y, 2.f);
        EXPECT_EQ(v_int->z, 3.f);

        auto v_float = make_unique<Vec3d>(1.f, 2.f, 3.f);
        EXPECT_EQ(v_float->x, 1.f);
        EXPECT_EQ(v_float->y, 2.f);
        EXPECT_EQ(v_float->z, 3.f);

        auto v_double = make_unique<Vec3d>(1.0, 2.0, 3.0);
        EXPECT_EQ(v_double->x, 1.f);
        EXPECT_EQ(v_double->y, 2.f);
        EXPECT_EQ(v_double->z, 3.f);

        for (int i = 0; i < REPETITIONS; ++i) {
            float x = getRandomFloat(), y = getRandomFloat(), z = getRandomFloat();
            Vec3d v(x, y, z);
            ASSERT_EQ(v.x, x);
            ASSERT_EQ(v.y, y);
            ASSERT_EQ(v.z, z);
        }
    }

    TEST_F(Vec3dTest, ConstructsViaCopyCtor) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            // checking construction
            Vec3d v(getRandomFloat(), getRandomFloat(), getRandomFloat());
            ASSERT_NO_THROW(Vec3d v_copy(v));

            // checking value correctness
            Vec3d v_copy(v);
            EXPECT_EQ(v.x, v_copy.x);
            EXPECT_EQ(v.y, v_copy.y);
            EXPECT_EQ(v.z, v_copy.z);
        }
    }

    TEST_F(Vec3dTest, AssignsViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            Vec3d v1(getRandomFloat(), getRandomFloat(), getRandomFloat());
            Vec3d v2;
            v2 = v1;
            EXPECT_EQ(v1.x, v2.x);
            EXPECT_EQ(v1.y, v2.y);
            EXPECT_EQ(v1.z, v2.z);
        }
    }

    TEST_F(Vec3dTest, ComparesByValueViaOperator) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();

            Vec3d v1(x1, y1, z1);
            Vec3d v2(x1, y1, z1);
            EXPECT_TRUE(v2 == v1);
            EXPECT_TRUE(v1 == v2);

            Vec3d v3(x2, y1, z1);
            EXPECT_FALSE(v1 == v3);
            EXPECT_FALSE(v3 == v1);

            Vec3d v4(x1, y2, z1);
            EXPECT_FALSE(v1 == v4);
            EXPECT_FALSE(v4 == v1);

            Vec3d v5(x1, y1, z2);
            EXPECT_FALSE(v1 == v5);
            EXPECT_FALSE(v5 == v1);
        }
    }

    TEST_F(Vec3dTest, ComputesDot) {    // NOLINT(cert-err58-cpp)
        for (int i = 0; i < REPETITIONS; ++i) {
            float x1 = getRandomFloat(), y1 = getRandomFloat(), z1 = getRandomFloat();
            float x2 = getRandomFloat(), y2 = getRandomFloat(), z2 = getRandomFloat();

            Vec3d v1(x1, y1, z1), v2(x2, y2, z2);

            std::array<float, 3> u1{x1, y1, z1}, u2{x2, y2, z2};

            ASSERT_EQ(v1.dot(v2), std::inner_product(u1.begin(), u1.end(), u2
                    .begin(), 0.f));
        }
    }

}  // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}