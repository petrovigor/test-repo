//
// Created by Ildar Suleimanov on 10.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(test_body_contains, ShouldBeTrue) {
    Candle c = {4, 2, 4, 3};
    EXPECT_TRUE(c.body_contains(3.5));

    c = {3, 2, 4, 4};
    EXPECT_TRUE(c.body_contains(3.5));

    c = {100, 2, 4, -100};
    EXPECT_TRUE(c.body_contains(0));

    c = {-100, 2, 4, 100};
    EXPECT_TRUE(c.body_contains(0));

    c = {100.00000001, 2, 4, 100};
    EXPECT_TRUE(c.body_contains(100.000000005));

    c = {100, 2, 4, 100.00000001};
    EXPECT_TRUE(c.body_contains(100.000000005));
}

TEST(test_body_contains, ShouldBeFalse) {
    Candle c = {4, 2, 4, 3};
    EXPECT_FALSE(c.body_contains(1));

    c = {3, 2, 4, 4};
    EXPECT_FALSE(c.body_contains(5));

    c = {100, 2, 4, -100};
    EXPECT_FALSE(c.body_contains(101));

    c = {-100, 2, 4, 100};
    EXPECT_FALSE(c.body_contains(-101));

    c = {100.00000001, 2, 4, 100};
    EXPECT_FALSE(c.body_contains(100.000000015));

    c = {100, 2, 4, 100.00000001};
    EXPECT_FALSE(c.body_contains(99.9999999999));
}
