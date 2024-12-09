#include "candle.hpp"
#include "tests.hpp"

#include <vector>
#include <functional>
#include <iostream>

//массив всех тестов, который мы заполняем в функции initTests
static std::vector<std::function<bool()>> tests;

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

    /* Добавление тестов для метода bodySize */
    tests.push_back(testBodySizeHigh);
    tests.push_back(testBodySizeRedCandle);
    tests.push_back(testBodySizeBorder);

    /* Добавление тестов для метода isGreen */
    tests.push_back(testIsGreen_1);
    tests.push_back(testIsGreen_2);
    tests.push_back(testIsGreen_3);

    /* Добавление тестов для метода isRed */
    tests.push_back(testIsRed_1);
    tests.push_back(testIsRed_2);
    tests.push_back(testIsRed_3);
}

int launchTests() {
    int total = 0;
    int passed = 0;
    int failed = 0;

    for (const auto& test : tests) {
        std::cout << "test #" << (total + 1);
        if (test()) {
            ++passed;
            std::cout << " passed\n";
        } else {
            ++failed;
            std::cout << " failed\n";
        }

        total += 1;
    }

    std::cout << "\ntests " << failed << '/' << total << " failed!\n";
    std::cout << "tests " << passed << '/' << total << " passed!\n";

    /* 0 = success */
    return total - passed;
}

int main() {
    initTests();

    return launchTests();
}
