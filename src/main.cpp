#include "common.hpp"
#include "OrderBook.hpp"
#include "Order.hpp"

int main(void)
{
    std::map<f64_t, std::deque<TradingSim::Order>> asks;
    std::map<f64_t, std::deque<TradingSim::Order>> bids;

    TradingSim::OrderBook orderBook {bids, asks};

    TradingSim::Order order1 {
        "some name", 
        123.56, 
        3, 
        OrderBookTypes::eOrderType::TYPE_ORDER_ASK, 
        OrderBookTypes::ePaymentType::TYPE_PAYMENT_MARKET
    };

    orderBook.addOrder(order1);

}
