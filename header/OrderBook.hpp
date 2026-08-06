#pragma once
#include <memory>
#include <utility>
#include <map>
#include <deque>
#include "Order.hpp"

namespace TradingSim
{

    class OrderBook
    {
        private:
        std::map<uint64_t, std::deque<Order>> bids;
        std::map<uint64_t, std::deque<Order>> asks;

        public:
        OrderBook(
            std::map<uint64_t, std::deque<Order>>,
            std::map<uint64_t, std::deque<Order>>
        );
        virtual ~OrderBook() = default;
        void addOrder(Order&);
        void removeOrder(Order&);
        std::pair<Order, Order> findPair();
        void processPair(std::pair<Order&, Order&>);

    };


};

