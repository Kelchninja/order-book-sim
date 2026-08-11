#pragma once
#include <string>
#include "common.hpp"
#include "eOrderType.hpp"

namespace TradingSim
{
    class Order : public OrderEntity
    {
        public:
        Order(uint64_t,
            std::string, 
            f64_t, 
            size_t, 
            OrderBookTypes::eOrderType, 
            OrderBookTypes::ePaymentType);
        virtual ~Order() = default;
        OrderBookTypes::eOrderType getOrderType() const noexcept;
        OrderBookTypes::ePaymentType getPaymentType() const noexcept;
        std::string getStockName() const noexcept;
        f64_t getPrice() const noexcept;
        size_t getAmount() const noexcept;
        
        // operators
        bool operator==(const Order&) const = default;

        private:
        std::string stockName;
        f64_t price;
        size_t amount;
        OrderBookTypes::eOrderType orderType;
        OrderBookTypes::ePaymentType paymentType;

    };

    class OrderEntity
    {
        private:
        const uint64_t id;

        public:
        OrderEntity(uint64_t);
        virtual ~OrderEntity() = default;
        uint64_t getId() const noexcept;
        static uint64_t getHash(uint64_t) noexcept;
        uint64_t getHash() const noexcept;
    };


};

