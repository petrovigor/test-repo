#include "candle.hpp"
#include "tests.hpp"

#include <vector>
#include <functional>
#include <iostream>
#include <cmath>

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

/* Проверка значения цены внутри тела свечи */
bool testContainsInside() {
    Candle candle{10.0, 20.0, 15.0, 18.0};

    return candle.contains(Price{16.0}) &&
           candle.contains(Price{15.0}) &&
           candle.contains(Price{17.0}) &&
           candle.contains(Price{18.0});
}

/* Проверка на значение цены вне диапазона */
bool testContainsOutside() {
    Candle candle{10.0, 20.0, 15.0, 18.0};

    return !candle.contains(Price{22.0}) && !candle.contains(Price{9.0});
}

/* Проверка значения цена на границе диапазона */
bool testContainsBorder() {
    Candle candle{20.0, 15.0, 15.0, 20.0};

    return candle.contains(Price{15.0}) && candle.contains(Price{15.0});
}

/* Проверка правильного расчета размера свечи,
 * когда верхняя цена больше нижней
 */
bool testFullSizeHigh() {
    Candle candle{Price{10.0}, Price{20.0}, Price{5.0}, Price{15.0}};

    return std::abs(candle.fullSize() - 15.0) < 0.0001;
}

/* Проверка правильного расчета размера свечи,
 * когда верхняя цена меньше нижней
 */
bool testFullSizeLow() {
    Candle candle{Price{20.0}, Price{10.0}, Price{15.0}, Price{5.0}};

    return std::abs(candle.fullSize() - 5.0) < 0.0001;
}

/* Проверка случая, когда все цены равны */
bool testFullSizeEquals() {
    Candle candle{Price{10.0}, Price{10.0}, Price{10.0}, Price{10.0}};

    return std::abs(candle.fullSize() - 0.0) < 0.0001;
}

void initTests() {
    /* Добавление тестов для метода bodyContains */
    tests.push_back(testBodyContainsGreenInside);
    tests.push_back(testBodyContainsRedInside);
    tests.push_back(testBodyContainsRedBorder);

    /* Добавлениие тестов для метода contains */
    tests.push_back(testContainsInside);
    tests.push_back(testContainsOutside);
    tests.push_back(testContainsBorder);

    /* Добавление тестов для метода fullSize */
    tests.push_back(testFullSizeHigh);
    tests.push_back(testFullSizeLow);
    tests.push_back(testFullSizeEquals);
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
