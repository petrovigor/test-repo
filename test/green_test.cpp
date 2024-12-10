//
// Created by Ildar Suleimanov on 10.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(test_is_green, ShouldBeTrue) {
    Candle c = {3, 2, 4, 4};
    EXPECT_TRUE(c.is_green());

    c = {2, 2, 4, 4};
    EXPECT_TRUE(c.is_green());

    c = {-100, 2, 4, 100};
    EXPECT_TRUE(c.is_green());

    c = {100, 2, 4, 100.00000001};
    EXPECT_TRUE(c.is_green());

    c = {99.999999999, 2, 4, 100};
    EXPECT_TRUE(c.is_green());
}

TEST(test_is_green, ShouldBeFalse) {
    Candle c = {4, 2, 4, 3};
    EXPECT_FALSE(c.is_green());

    c = {2, 2, 4, 1};
    EXPECT_FALSE(c.is_green());

    c = {100, 2, 4, -100};
    EXPECT_FALSE(c.is_green());

    c = {100.00000001, 2, 4, 100};
    EXPECT_FALSE(c.is_green());

    c = {99.99999999, 2, 4, 99.99999998};
    EXPECT_FALSE(c.is_green());
}

TEST(test_is_green, ShouldBeFalseBecauseEqual) {
    Candle c = {4, 2, 4, 4};
    EXPECT_FALSE(c.is_green());

    c = {-4, 2, 4, -4};
    EXPECT_FALSE(c.is_green());

    c = {0, 2, 4, 0};
    EXPECT_FALSE(c.is_green());

    c = {0.000000001, 2, 4, 0.000000001};
    EXPECT_FALSE(c.is_green());
}
