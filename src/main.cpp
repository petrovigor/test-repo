#include "candle.hpp"
#include "tests.hpp"

#include <vector>
#include <functional>
#include <iostream>

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

/* Проверка, что в зеленой свече цена внутри тела */
bool testBodyContainsGreenInside() {
    Candle candle{10.0, 20.0, 20.0, 10.0};

    return candle.bodyContains(Price{10.0});
}

/* Проверка, что в красной свече цена внутри тела */
bool testBodyContainsRedInside() {
    Candle candle{20.0, 10.0, 20.0, 10.0};

    return candle.bodyContains(Price{15.0});
}

/* Проверка, что в красной свече цена на границе тела */
bool testBodyContainsRedBorder() {
    Candle candle{20.0, 10.0, 20.0, 10.0};

    return candle.bodyContains(Price{10.0}) && candle.bodyContains(Price{20.0});
}

void initTests() {
    tests.push_back(testBodyContainsGreenInside);
    tests.push_back(testBodyContainsRedInside);
    tests.push_back(testBodyContainsRedBorder);
}

int launchTests() {
    int total = 0;
    int passed = 0;

    for (const auto& test : tests)
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

    /* 0 = success */
    return total - passed;
}

int main() {
    initTests();

    return launchTests();
}
