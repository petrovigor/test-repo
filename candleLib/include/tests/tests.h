#pragma once

#ifndef CANDLELIB_INCLUDE_TESTS_TESTS_H_
#define CANDLELIB_INCLUDE_TESTS_TESTS_H_

// Тело свечи содержит цену при условии зеленой свечи
bool test_BodyContains_IfGreen();
// Тело свечи содержит цену при условии красной свечи
bool test_BodyContains_IfRed();
// Тело свечи не содержит цену при условии зеленой свечи
bool test_BodyContains_OutOfBorderIfGreen();

// Тени свечи содержат цену при условии зеленой свечи
bool test_Contains_IfGreen();
// Тени свечи содержат цену при условии красной свечи
bool test_Contains_IfRed();
// Тени свечи не содержат цену при условии зеленой свечи
bool test_Contains_OutOfBorderIfGreen();

// Полный размер нормальной зеленой свечи
bool test_FullSize_IfGreen();
// Параметр high меньше low (candle.low = high и candle.high = low)
bool test_FullSize_IfLowAdvantageToHigh();
// Параметр high или low при создании свечи задан отрицательным (candle.low = -low или candle.high = -high)
bool test_FullSize_IfNegativeHighOrLow();

bool test_BodySize_IfGreen();
bool test_BodySize_IfRed();
bool test_BodySize_IfGreenAndRed();

bool test_IsGreen_IfGreen();
bool test_IsGreen_IfRed();
bool test_IsGreen_IfNone();

bool test_IsRed_IfGreen();
bool test_IsRed_IfRed();
bool test_IsRed_IfNone();

#endif