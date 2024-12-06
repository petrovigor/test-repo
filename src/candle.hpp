#ifndef __CANDLE_HPP__
#define __CANDLE_HPP__

#include <cstdint>
#include <string>

using Price = double;

struct Candle {
public:
    Price m_open;
    Price m_high;
    Price m_low;
    Price m_close;

public:
    Candle() = default;
    Candle(Price open, Price high, Price low, Price close);

public:
    /* находится ли цена внутри тела этой свечи */
    bool bodyContains(const Price& price) const noexcept;

    /* находится ли цена внутри тела и теней
     * другими словами, касается ли цена
     * тела или теней свечи
     */
    bool contains(const Price& price) const noexcept;

    /* возвращает размер целой свечи, включая тени */
    double fullSize() const noexcept;

    /* возвращает размер тела свечи */
    double bodySize() const noexcept;

    /* Проверяет, является ли цвет зеленым */
    bool isGreen() const noexcept;

    /* Проверяет, является ли цвет красным */
    bool isRed() const noexcept;
};

#endif
