#include "CardPayment.h"
#include <iostream>

bool CardPayment::pay(DataStore *ds, float amount)
{
    if (amount >= ds->get_price())
    {
        ds->set_cf(amount);
        std::cout << "[CardPayment] Payment accepted.\n";
        return true;
    }
    else
    {
        ds->set_cf(0);
        std::cout << "[CardPayment] Insufficient balance.\n";
        return false;
    }
}
