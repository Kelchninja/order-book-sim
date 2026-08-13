#include <gtest/gtest.h>

#include <functional>

#include "Price.hpp"

using TradingSim::Price;

TEST(PriceTest, DefaultIsZero)
{
    Price p;
    EXPECT_EQ(p.ticks(), 0);
    EXPECT_DOUBLE_EQ(p.toDouble(), 0.0);
}

TEST(PriceTest, ConstructsFromDoubleWithScale)
{
    Price p{1.5};
    EXPECT_EQ(p.ticks(), 15000);
    EXPECT_DOUBLE_EQ(p.toDouble(), 1.5);
}

TEST(PriceTest, RoundsToNearestTick)
{
    // 1.23456 * 10000 = 12345.6  -> rundet auf 12346
    EXPECT_EQ(Price{1.23456}.ticks(), 12346);
    EXPECT_EQ(Price{-1.23456}.ticks(), -12346);
}

TEST(PriceTest, FromTicks)
{
    Price p = Price::fromTicks(25000);
    EXPECT_EQ(p.ticks(), 25000);
    EXPECT_DOUBLE_EQ(p.toDouble(), 2.5);
}

TEST(PriceTest, Arithmetic)
{
    Price a{1.0};
    Price b{0.25};
    EXPECT_EQ((a + b).ticks(), 12500);
    EXPECT_EQ((a - b).ticks(), 7500);
}

TEST(PriceTest, Comparison)
{
    EXPECT_LT(Price{1.0}, Price{2.0});
    EXPECT_GT(Price{2.0}, Price{1.0});
    EXPECT_EQ(Price{1.5}, Price{1.5});
    EXPECT_NE(Price{1.5}, Price{1.6});
}

TEST(PriceTest, ToString)
{
    EXPECT_EQ(Price{150.0}.toString(), "150.0");
    EXPECT_EQ(Price{1.23456}.toString(), "1.2346");
}

TEST(PriceTest, HashMatchesTicksHash)
{
    Price p{3.14};
    EXPECT_EQ(std::hash<Price>{}(p), std::hash<Price::tick_t>{}(p.ticks()));
}
