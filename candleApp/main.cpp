﻿#pragma once

#include <vector>
#include <functional>
#include <iostream>

#include "tests/tests.h"

// массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

void initTests()
{
  tests.push_back(test_BodyContains_IfGreen);
  tests.push_back(test_BodyContains_IfRed);
  tests.push_back(test_BodyContains_OutOfBorderIfGreen);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  for (const auto &test : tests)
  {
    std::cout << "test #" << (total + 1);
    if (test())
    {
      passed += 1;
      std::cout << " passed\n";
    }
    else
    {
      std::cout << " failed\n";
    }
    total += 1;
  }

  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  return total - passed;
}

int main()
{
  initTests();
  return launchTests();
}