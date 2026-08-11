


#include "Order.hpp"

namespace TradingSim
{
    // Order
    Order::Order(uint64_t orderID,
            std::string stockName, 
            f64_t price, 
            size_t amount, 
            OrderBookTypes::eOrderType orderType, 
            OrderBookTypes::ePaymentType paymentType)
    : OrderEntity(orderID),
    stockName(stockName), 
    price(price), 
    amount(amount), 
    orderType(orderType), 
    paymentType(paymentType) {};

    size_t Order::getAmount() const noexcept
    {
        return amount;
    };

    f64_t Order::getPrice() const noexcept
    {
        return price;
    };

    std::string Order::getStockName() const noexcept
    {
        return stockName;
    };

    OrderBookTypes::eOrderType Order::getOrderType() const noexcept
    {
        return orderType;
    };

    OrderBookTypes::ePaymentType Order::getPaymentType() const noexcept
    {
        return paymentType;
    };



    // IOrderEntity
    OrderEntity::OrderEntity(uint64_t id)
    : id(id) {};

    uint64_t OrderEntity::getHash(uint64_t id) noexcept
    {
        return std::hash<uint64_t>{}(id);
    }

    uint64_t OrderEntity::getHash() const noexcept
    {
        return getHash(id);
    }

};

