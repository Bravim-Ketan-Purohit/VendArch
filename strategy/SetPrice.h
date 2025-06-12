#ifndef SETPRICE_H
#define SETPRICE_H

class SetPrice
{
public:
    virtual void set_price(float price) = 0;
    virtual ~SetPrice() = default;
};

#endif
