#pragma once
#include <string>
#include "common.hpp"
#include "eOrderType.hpp"

namespace TradingSim
{
    class Order
    {
        public:
        Order(std::string, 
            f64_t, 
            size_t, 
            OrderBookTypes::eOrderType, 
            OrderBookTypes::ePaymentType);
        virtual ~Order() = default;
        OrderBookTypes::eOrderType getOrderType();
        OrderBookTypes::ePaymentType getPaymentType();
        std::string getStockName();
        f64_t getPrice();
        size_t getAmount();

        private:
        std::string stockName;
        f64_t price;
        size_t amount;
        OrderBookTypes::eOrderType orderType;
        OrderBookTypes::ePaymentType paymentType;

    };

};

