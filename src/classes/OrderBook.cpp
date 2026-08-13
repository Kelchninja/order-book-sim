#include "OrderBook.hpp"
#include "eOrderType.hpp"

#include <iostream>


namespace TradingSim
{
    
    OrderBook::OrderBook(
        OrderTree asks,
        OrderTree bids,
        HandleTable handles)
        : asks{asks}, bids{bids}, handles{handles} {}
    
    void OrderBook::addOrder(Order order)
    {
        bool isAsk = (order.getOrderType() == OrderBookTypes::eOrderType::TYPE_ORDER_ASK);
        eSide side = isAsk ? eSide::SELL : eSide::BUY;
        auto& book = isAsk ? asks : bids;

        uint64_t id = order.getId();
        Price price = order.getPrice();

        auto& ol = book[price];
        auto it = ol.insert(ol.end(), std::move(order));

        handles.emplace(id, Handle{side, price, it});
    }

    void OrderBook::cancelOrder(Order& order)
    {
        auto handle_it = handles.find(order.getId());
        if (handle_it == handles.end())
        {
            return;
        }

        auto& handle = handle_it->second;

        if (handle.side == eSide::SELL)
        {
            asks[handle.price].erase(handle.it);
        }
        else
        {
            bids[handle.price].erase(handle.it);
        }

        handles.erase(handle_it);
    }

    std::optional<std::list<Order>::iterator> inline OrderBook::findMatch(const Order& order)
    {
        using OrderBookTypes::eOrderType;
        using OrderBookTypes::ePaymentType;
        
        auto& book = (order.getOrderType() == eOrderType::TYPE_ORDER_ASK) 
        ? asks : bids;

        auto& orderlist = book[order.getPrice()];
        auto it = orderlist.begin();

        return it;
    }

    void OrderBook::processOrder(Order order)
    {
        auto match = findMatch(order);
        if (match.has_value())
        {
            executeTrade(order, **match);
            
            cancelOrder(order);
            cancelOrder(**match);
        }
        else
        {
            addOrder(std::move(order));
        }

    }

    void OrderBook::executeTrade(Order& taker, Order& maker)
    {
        std::cout << "Trade executed:" << taker << maker << std::endl;
    }
    
    
}
