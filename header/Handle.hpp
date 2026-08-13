#pragma once

#include <list>

#include "common.hpp"
#include "Order.hpp"
#include "Price.hpp"

namespace TradingSim
{

    enum class eSide
    {
        BUY,
        SELL
    };

    struct Handle
    {
        eSide side;
        Price price;
        std::list<Order>::iterator it;
    };

}