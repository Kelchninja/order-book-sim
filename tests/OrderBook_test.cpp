#include <gtest/gtest.h>

#include <cstdint>

#include "Order.hpp"
#include "OrderBook.hpp"
#include "Price.hpp"

using TradingSim::Order;
using TradingSim::OrderBook;
using TradingSim::Price;
using OrderBookTypes::eOrderType;
using OrderBookTypes::ePaymentType;

namespace
{
    Order ask(uint64_t id, double price, size_t amount = 10)
    {
        return Order{id, "AAPL", Price{price}, amount,
                     eOrderType::TYPE_ORDER_ASK,
                     ePaymentType::TYPE_PAYMENT_LIMIT};
    }

    Order bid(uint64_t id, double price, size_t amount = 10)
    {
        return Order{id, "AAPL", Price{price}, amount,
                     eOrderType::TYPE_ORDER_BID,
                     ePaymentType::TYPE_PAYMENT_LIMIT};
    }
}

TEST(OrderBookTest, FindMatchReturnsNulloptWhenEmpty)
{
    OrderBook book;
    EXPECT_FALSE(book.findMatch(ask(1, 100.0)).has_value());
}

TEST(OrderBookTest, IncomingAskMatchesRestingBidAtSamePrice)
{
    OrderBook book;
    book.addOrder(bid(1, 100.0));

    auto match = book.findMatch(ask(2, 100.0));
    ASSERT_TRUE(match.has_value());
    EXPECT_EQ((*match)->getId(), 1u);
}

TEST(OrderBookTest, IncomingBidMatchesRestingAsk)
{
    OrderBook book;
    book.addOrder(ask(1, 100.0));

    auto match = book.findMatch(bid(2, 100.0));
    ASSERT_TRUE(match.has_value());
    EXPECT_EQ((*match)->getId(), 1u);
}

TEST(OrderBookTest, NoMatchAtDifferentPrice)
{
    OrderBook book;
    book.addOrder(bid(1, 100.0));
    // findMatch macht (aktuell) nur einen exakten Preis-Match
    EXPECT_FALSE(book.findMatch(ask(2, 101.0)).has_value());
}

TEST(OrderBookTest, SameSideIsNotMatched)
{
    OrderBook book;
    book.addOrder(ask(1, 100.0));
    // ein eingehender ASK sucht in den bids -> dort ist nichts
    EXPECT_FALSE(book.findMatch(ask(2, 100.0)).has_value());
}

TEST(OrderBookTest, CancelRemovesRestingOrder)
{
    OrderBook book;
    Order resting = bid(1, 100.0);
    book.addOrder(resting); // by value -> Kopie im Buch, `resting` bleibt gueltig

    ASSERT_TRUE(book.findMatch(ask(2, 100.0)).has_value());

    book.cancelOrder(resting);
    EXPECT_FALSE(book.findMatch(ask(2, 100.0)).has_value());
}

TEST(OrderBookTest, CancelUnknownOrderIsNoop)
{
    OrderBook book;
    Order never_added = bid(99, 100.0);
    EXPECT_NO_THROW(book.cancelOrder(never_added));
}
