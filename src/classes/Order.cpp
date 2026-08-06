


#include "Order.hpp"

namespace TradingSim
{
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

