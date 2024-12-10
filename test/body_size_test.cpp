//
// Created by Ildar Suleimanov on 10.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(test_body_size, ShouldBeZero) {
    Candle c = {4, 2, 4, 4};
    EXPECT_EQ(0, c.body_size());

    c = {-4, 2, 4, -4};
    EXPECT_EQ(0, c.body_size());
}

TEST(test_body_size, ShouldBePositive) {
    Candle c = {4, 2, 4, 2};
    EXPECT_GT(c.body_size(), 0);

    c = {-4, 2, 4, -9};
    EXPECT_GT(c.body_size(), 0);
}
