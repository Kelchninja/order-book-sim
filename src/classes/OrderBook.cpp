#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>

namespace TradingSim
{
    OrderBook::OrderBook(
        std::map<f64_t, std::deque<Order>> asks,
        std::map<f64_t, std::deque<Order>> bids)
        : asks(asks), bids(bids) {}
    
    void OrderBook::addOrder(Order& order)
    {
        auto& book = (order.getOrderType() == OrderBookTypes::TYPE_ORDER_ASK)
            ? asks
            : bids;

        book[order.getPrice()].push_back(order);
    };
    
}
