#pragma once
#include <memory>
#include <utility>
#include <map>
#include <deque>
#include "Order.hpp"
#include <vector>

namespace TradingSim
{

    class OrderBook
    {
        private:
        std::map<f64_t, std::deque<Order>> asks;
        std::map<f64_t, std::deque<Order>> bids;
        std::vector<std::list<OrderEntity*>> pendingOrders;;

        public:
        OrderBook(
            std::map<f64_t, std::deque<Order>>,
            std::map<f64_t, std::deque<Order>>,
            std::vector<std::list<OrderEntity*>>
        );
        virtual ~OrderBook() = default;
        void addOrder(Order);
        Order* findOrder(uint64_t);
        std::pair<Order, Order> findPair(Order& order) noexcept;
        void processPair(std::pair<Order&, Order&>);
        Order& operator[](Order& other) const noexcept; // for fun access
    };


};

