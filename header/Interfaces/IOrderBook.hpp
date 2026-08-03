

class IOrderBook
{
    public:
        virtual ~IOrderBook() = default;
        void addOrder(IOrder order);

}


