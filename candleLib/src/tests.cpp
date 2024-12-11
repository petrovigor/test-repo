#pragma once

#include <cmath>
#include "tests/tests.h"
#include "candle/candle.h"

// Тело свечи содержит цену при условии зеленой свечи
bool test_BodyContains_IfGreen()
{
    Candle candle{15.0, 0.0, 0.0, 20.0};
    return candle.body_contains(15.0) &&
           candle.body_contains(17.5) &&
           candle.body_contains(20.0);
}

// Тело свечи содержит цену при условии красной свечи
bool test_BodyContains_IfRed()
{
    Candle candle{20.0, 0.0, 0.0, 15.0};
    return candle.body_contains(20.0) &&
           candle.body_contains(17.5) &&
           candle.body_contains(15.0);
}

// Тело свечи не содержит цену при условии зеленой свечи
bool test_BodyContains_OutOfBorderIfGreen()
{
    Candle candle{15.0, 0.0, 0.0, 20.0};
    return !candle.body_contains(14.99999) &&
           !candle.body_contains(20.00001) &&
           !candle.body_contains(5.0) &&
           !candle.body_contains(25.0);
}

// Тени свечи содержат цену при условии зеленой свечи
bool test_Contains_IfGreen()
{
    Candle candle{15.0, 25.0, 10.0, 20.0};
    return candle.contains(25.0) &&
           candle.contains(17.5) &&
           candle.contains(10.0);
}

// Тени свечи содержат цену при условии красной свечи
bool test_Contains_IfRed()
{
    Candle candle{20.0, 25.0, 10.0, 15.0};
    return candle.contains(25.0) &&
           candle.contains(17.5) &&
           candle.contains(10.0);
}

// Тени свечи не содержат цену при условии зеленой свечи
bool test_Contains_OutOfBorderIfGreen()
{
    Candle candle{15.0, 25.0, 10.0, 20.0};
    return !candle.contains(25.00001) &&
           !candle.contains(9.99999) &&
           !candle.contains(5.0) &&
           !candle.contains(30.0);
}

// Полный размер нормальной зеленой свечи
bool test_FullSize_IfGreen()
{
    Candle candle{0.0, 25.0, 10.0, 0.0};
    return std::abs(candle.full_size() - 15.0) < 1e-3;
}

// При создании свечи параметр high меньше low (candle.low = high и candle.high = low)
bool test_FullSize_IfLowAdvantageToHigh()
{
    Candle candle{0.0, 10.0, 25.0, 0.0};
    return std::abs(candle.full_size() - 15.0) < 1e-3;
}

// Параметр high или low при создании свечи задан отрицательным (candle.low = -low или candle.high = -high)
bool test_FullSize_IfNegativeHighOrLow()
{
    return !(std::abs(Candle(0.0, -10.0, 25.0, 0.0).full_size() - 15.0) < 1e-3) &&
           !(std::abs(Candle(0.0, 10.0, -25.0, 0.0).full_size() - 15.0) < 1e-3);
}

// Размер тела нормальной зеленой свечи
bool test_BodySize_IfGreen()
{
    Candle candle{15.0, 25.0, 10.0, 20.0};
    return std::abs(candle.body_size() - 5.0) < 1e-3;
}

// Размер тела нормальной красной свечи
bool test_BodySize_IfRed()
{
    Candle candle{20.0, 25.0, 10.0, 15.0};
    return std::abs(candle.body_size() - 5.0) < 1e-3;
}

// Размер тела нулевой свечи
bool test_BodySize_IfNullBody()
{
    Candle candle{15.0, 25.0, 10.0, 15.0};
    return std::abs(candle.body_size() - 0.0) < 1e-3;
}