


#include "Order.hpp"

namespace TradingSim
{
    Order::Order(std::string stockName, 
            f64_t price, 
            size_t amount, 
            OrderBookTypes::eOrderType orderType, 
            OrderBookTypes::ePaymentType paymentType)
    : stockName(stockName), 
    price(price), 
    amount(amount), 
    orderType(orderType), 
    paymentType(paymentType) {};

    size_t Order::getAmount()
    {
        return amount;
    };

    f64_t Order::getPrice()
    {
        return price;
    };

    std::string Order::getStockName()
    {
        return stockName;
    };

    OrderBookTypes::eOrderType Order::getOrderType()
    {
        return orderType;
    };

    OrderBookTypes::ePaymentType Order::getPaymentType()
    {
        return paymentType;
    };

};

