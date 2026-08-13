#pragma once

#include <map>
#include <unordered_map>
#include <optional>

#include "Handle.hpp"
#include "Order.hpp"
#include "Price.hpp"

namespace TradingSim
{
    using OrderTree = std::map<Price, std::list<Order>>;
    using HandleTable = std::unordered_map<uint64_t, Handle>;

    class OrderBook
    {
        private:
        OrderTree asks;
        OrderTree bids;
        HandleTable handles;

        public:
        OrderBook(
            OrderTree,
            OrderTree,
            HandleTable
        );
        OrderBook();

        virtual ~OrderBook() = default;

        void addOrder(Order);
        void cancelOrder(Order&);

        std::optional<std::list<Order>::iterator> inline findMatch(const Order&);
        void processOrder(Order);
        void executeTrade(Order&, Order&);
    };


}

