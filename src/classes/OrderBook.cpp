#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>
#include <list>

namespace TradingSim
{
    OrderBook::OrderBook(
        std::map<f64_t, std::deque<Order>> asks,
        std::map<f64_t, std::deque<Order>> bids,
        std::vector<std::list<OrderEntity*>> pendingOrders)
        : asks(asks), bids(bids), pendingOrders(pendingOrders) {};
    
    void OrderBook::addOrder(Order order)
    {
        auto& book = (order.getOrderType() == OrderBookTypes::eOrderType::TYPE_ORDER_ASK)
        ? asks : bids;

        book[order.getPrice()].push_back(order);

        pendingOrders[order.getId()];
    };

    // Order* OrderBook::findOrder(uint64_t orderId)
    // {
    //     uint64_t index = OrderEntity::getHash(orderId);
    //     return orderID;
    // };
    
}
