//
// Created by Ildar Suleimanov on 09.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(test_is_red, ShouldBeTrue) {
    Candle c = {4, 2, 4, 3};
    EXPECT_TRUE(c.is_red());

    c = {4, 2, 4, 2};
    EXPECT_TRUE(c.is_red());

    c = {100, 2, 4, -100};
    EXPECT_TRUE(c.is_red());

    c = {100.00000001, 2, 4, 100};
    EXPECT_TRUE(c.is_red());

    c = {100, 2, 4, 99.999999999};
    EXPECT_TRUE(c.is_red());
}

TEST(test_is_red, ShouldBeFalse) {
    Candle c = {4, 2, 4, 4};
    EXPECT_FALSE(c.is_red());

    c = {2, 2, 4, 4};
    EXPECT_FALSE(c.is_red());

    c = {-100, 2, 4, 100};
    EXPECT_FALSE(c.is_red());

    c = {100, 2, 4, 100.00000001};
    EXPECT_FALSE(c.is_red());

    c = {99.999999999, 2, 4, 100};
    EXPECT_FALSE(c.is_red());
}

TEST(test_is_red, ShouldBeFalseBecauseEqual) {
    Candle c = {4, 2, 4, 4};
    EXPECT_FALSE(c.is_red());

    c = {-4, 2, 4, -4};
    EXPECT_FALSE(c.is_red());

    c = {0, 2, 4, 0};
    EXPECT_FALSE(c.is_red());

    c = {0.000000001, 2, 4, 0.000000001};
    EXPECT_FALSE(c.is_red());
}
