#pragma once

#ifndef CANDLELIB_INCLUDE_TESTS_TESTS_H_
#define CANDLELIB_INCLUDE_TESTS_TESTS_H_

// Тело свечи содержит цену при условии зеленой свечи
bool test_BodyContains_IfGreen();
// Тело свечи содержит цену при условии красной свечи
bool test_BodyContains_IfRed();
// Тело свечи не содержит цену при условии зеленой свечи
bool test_BodyContains_OutOfBorderIfGreen();

// Тело и фитильсвечи содержит цену при условии зеленой свечи
bool test_Contains_IfGreen();
// Тело и фитиль свечи содержит цену при условии красной свечи
bool test_Contains_IfRed();
// Тело и фитиль свечи не содержит цену при условии зеленой свечи
bool test_Contains_OutOfBorderIfGreen();

bool test_FullSize_IfGreen();
bool test_FullSize_IfRed();
bool test_FullSize_IfGreenAndRed();

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