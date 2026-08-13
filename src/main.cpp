#include "common.hpp"
#include "OrderBook.hpp"
#include "Order.hpp"

int main(void)
{

    TradingSim::OrderBook orderBook{};

    TradingSim::Order order1 {
        1234567890,
        "some name", 
        123.56, 
        3, 
        OrderBookTypes::eOrderType::TYPE_ORDER_ASK, 
        OrderBookTypes::ePaymentType::TYPE_PAYMENT_MARKET
    };

}
