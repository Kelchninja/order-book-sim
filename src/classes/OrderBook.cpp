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
        auto it = asks.find(order.getPrice());
        for (auto i{0uz}; i < it->second.size(); ++i)
        {
            std::cout << it->second.at(i).getPrice() << std::endl;
        }
    };
    
}
