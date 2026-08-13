#pragma once

#include "common.hpp"
#include "eOrderType.hpp"

#include <string>

namespace TradingSim
{
    class Price
    {
        public:
        using tick_t = int64_t;

        static constexpr tick_t Scale = 10000;

        constexpr Price() noexcept : ticks_(0) {}

        explicit Price(f64_t value)
            : ticks_(static_cast<tick_t>(value * Scale + (value >= 0 ? 0.5 : -0.5)))
        {}

        static constexpr Price fromTicks(tick_t ticks) noexcept
        {
            Price p;
            p.ticks_ = ticks;
            return p;
        }

        constexpr tick_t ticks() const noexcept { return ticks_; }

        f64_t toDouble() const noexcept
        {
            return static_cast<f64_t>(ticks_) / Scale;
        }

        constexpr auto operator<=>(const Price&) const = default;

        constexpr Price operator+(const Price& other) const noexcept
        {
            return fromTicks(ticks_ + other.ticks_);
        }

        constexpr Price operator-(const Price& other) const noexcept
        {
            return fromTicks(ticks_ - other.ticks_);
        }

        std::string toString() const
        {
            tick_t whole = ticks_ / Scale;
            tick_t frac = ticks_ % Scale;
            if (frac < 0) frac = -frac;
            return std::to_string(whole) + "." + std::to_string(frac);
        }

        private:
        tick_t ticks_;
    };

}

template <>
struct std::hash<TradingSim::Price>
{
    size_t operator()(const TradingSim::Price& p) const noexcept
    {
        return std::hash<TradingSim::Price::tick_t>{}(p.ticks());
    }
};
