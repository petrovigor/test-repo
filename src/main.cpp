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

/* Создание свечи с ценой открытия 5 и ценой закрытия 20 */
bool testBodySizeHigh() {
    Candle candle{Price{5.0}, Price{20.0}, Price{5.0}, Price{20.0}};

    return std::abs(candle.bodySize() - 15.0) < 0.0001;
}

/* Проверка вычисления размера тела при условии,
 * что цена закрытия ниже цены открытия
 */
bool testBodySizeRedCandle() {
    Candle candle{Price{20.0}, Price{30.0}, Price{10.0}, Price{10.0}};

    return std::abs(candle.bodySize() - 10.0) < 0.0001;
}

/* Проверка свечи, при условии, что цена открытия равна цене закрытия */
bool testBodySizeBorder() {
    Candle candle{Price{10.0}, Price{10.0}, Price{10.0}, Price{10.0}};

    return std::abs(candle.bodySize() - 0.0) < 0.0001;
}

/* Проверка на создание зеленой свечи */
bool testIsGreen_1() {
    Candle candle{Price{10.0}, Price{20.0}, Price{5.0}, Price{15.0}};

    return candle.isGreen();
}

/* Проверка на создание красной свечи,
 * инвертирование проверки на зеленую свечу
 */
bool testIsGreen_2() {
    Candle candle{Price{20.0}, Price{30.0}, Price{10.0}, Price{10.0}};

    return !candle.isGreen();
}

/* Проверка на создание свечи с равными ценами открытия и закрытия,
 * инвертирование проверки на зеленую свечу
 */
bool testIsGreen_3() {
    Candle candle{Price{10.0}, Price{10.0}, Price{10.0}, Price{10.0}};

    return !candle.isGreen();
}

/* Проверка на создание красной свечи */
bool testIsRed_1() {
    Candle candle{Price(20.0), Price(30.0), Price(10.0), Price(10.0)};

    return candle.isRed();
}

/* Проверка на создание зеленой свечи,
 * инвертирование проверки на красную свечу
 */
bool testIsRed_2() {
    Candle candle{Price(10.0), Price(20.0), Price(5.0), Price(15.0)};

    return !candle.isRed();
}

/* Проверка на создание свечи с равными ценами открытия и закрытия,
 * инвертирование проверки на красную свечу
 */
bool testIsRed_3() {
    Candle candle{Price(10.0), Price(10.0), Price(10.0), Price(10.0)};

    return !candle.isRed();
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
