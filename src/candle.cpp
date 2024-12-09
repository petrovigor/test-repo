#include "candle.hpp"

#include <string>
#include <stdexcept>

Candle::Candle(Price open, Price high, Price low, Price close)
    : m_open(open), m_high(high) , m_low(low) , m_close(close) {}

bool Candle::bodyContains(const Price& price) const noexcept {
    if (isGreen()) {
        const Price& max = m_close;
        const Price& min = m_open;

        return price >= min && price <= max;
    } else {
        const Price& max = m_open;
        const Price& min = m_close;

        return price >= min && price <= max;
    }
}

bool Candle::contains(const Price& price) const noexcept {
    return price >= m_low && price <= m_high;
}

double Candle::fullSize() const noexcept {
    return std::abs(m_low - m_high);
}

double Candle::bodySize() const noexcept {
    return std::abs(m_open - m_close);
}

bool Candle::isGreen() const noexcept {
    return m_close > m_open;
}

bool Candle::isRed() const noexcept {
    return m_close < m_open;
}
