#pragma once

#include "Price.hpp"
#include "eOrderType.hpp"

#include <ostream>


namespace TradingSim
{
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

    class Order : public OrderEntity
    {
        friend std::ostream& operator<<(std::ostream& os, const Order& order);

        public:
        Order(uint64_t,
            std::string, 
            Price, 
            size_t, 
            OrderBookTypes::eOrderType, 
            OrderBookTypes::ePaymentType);
        virtual ~Order() = default;

        OrderBookTypes::eOrderType getOrderType() const noexcept;
        OrderBookTypes::ePaymentType getPaymentType() const noexcept;
        std::string getStockName() const noexcept;
        Price getPrice() const noexcept;
        size_t getAmount() const noexcept;
        
        
        // operators
        bool operator==(const Order&) const = default;
        
        private:
        std::string stockName;
        Price price;
        size_t amount;
        OrderBookTypes::eOrderType orderType;
        OrderBookTypes::ePaymentType paymentType;

    };


};

