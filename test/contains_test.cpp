//
// Created by Ildar Suleimanov on 10.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(test_contains, ShouldBeTrue) {
    Candle c = {4, 4, 2, 2};
    EXPECT_TRUE(c.contains(2.1));

    c = {100, 2, -4, -100};
    EXPECT_TRUE(c.contains(0));

    c = {5, 100.00000001, 100, 1};
    EXPECT_TRUE(c.contains(100.000000005));

    c = {2, 100, 99.999999999, 4};
    EXPECT_TRUE(c.contains(99.9999999991));

    c = {2, 100.1111111, 99.999999999, 4};
    EXPECT_TRUE(c.contains(100));
}

TEST(test_contains, ShouldBeFalse) {
    Candle c = {4, 2, 4, 4};
    EXPECT_FALSE(c.contains(5));

    c = {4, 2, 4, 4};
    EXPECT_FALSE(c.contains(1));

    c = {2, 4, 2, 4};
    EXPECT_FALSE(c.contains(5));

    c = {2, 4, 2, 4};
    EXPECT_FALSE(c.contains(1));
}
