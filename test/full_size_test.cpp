//
// Created by Ildar Suleimanov on 10.12.2024.
//
#include "../candle.h"
#include <gtest/gtest.h>

TEST(full_size, ShouldBeZero) {
    Candle c = {1, 4, 4, 2};
    EXPECT_EQ(0, c.full_size());

    c = {1, -4, -4, -2};
    EXPECT_EQ(0, c.full_size());
}

TEST(full_size, ShouldBePositive) {
    Candle c = {4, 2, 4, 2};
    EXPECT_GT(c.full_size(), 0);

    c = {-4, 2, 4, -5};
    EXPECT_GT(c.full_size(), 0);
}
