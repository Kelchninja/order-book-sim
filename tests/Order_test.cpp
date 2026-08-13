#include <gtest/gtest.h>

#include <cstdint>
#include <functional>

#include "Order.hpp"
#include "Price.hpp"

using TradingSim::Order;
using TradingSim::Price;
using OrderBookTypes::eOrderType;
using OrderBookTypes::ePaymentType;

namespace
{
    Order makeOrder(uint64_t id = 1)
    {
        return Order{id, "AAPL", Price{150.0}, 10,
                     eOrderType::TYPE_ORDER_ASK,
                     ePaymentType::TYPE_PAYMENT_LIMIT};
    }
}

TEST(OrderTest, StoresAllFields)
{
    Order o = makeOrder(42);
    EXPECT_EQ(o.getId(), 42u);
    EXPECT_EQ(o.getStockName(), "AAPL");
    EXPECT_EQ(o.getPrice().ticks(), Price{150.0}.ticks());
    EXPECT_EQ(o.getAmount(), 10u);
    EXPECT_EQ(o.getOrderType(), eOrderType::TYPE_ORDER_ASK);
    EXPECT_EQ(o.getPaymentType(), ePaymentType::TYPE_PAYMENT_LIMIT);
}

TEST(OrderTest, BidMarketOrder)
{
    Order o{7, "MSFT", Price{99.5}, 5,
            eOrderType::TYPE_ORDER_BID,
            ePaymentType::TYPE_PAYMENT_MARKET};
    EXPECT_EQ(o.getOrderType(), eOrderType::TYPE_ORDER_BID);
    EXPECT_EQ(o.getPaymentType(), ePaymentType::TYPE_PAYMENT_MARKET);
    EXPECT_EQ(o.getStockName(), "MSFT");
    EXPECT_EQ(o.getAmount(), 5u);
}

TEST(OrderEntityTest, HashMatchesStdHash)
{
    Order o = makeOrder(1234567890);
    EXPECT_EQ(o.getHash(), std::hash<uint64_t>{}(1234567890u));
    EXPECT_EQ(Order::getHash(1234567890u), std::hash<uint64_t>{}(1234567890u));
    EXPECT_EQ(o.getHash(), Order::getHash(o.getId()));
}
