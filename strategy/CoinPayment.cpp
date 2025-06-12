#include "CoinPayment.h"
#include <iostream>

bool CoinPayment::pay(DataStore *ds, float amount)
{
    float current = ds->get_cf();
    ds->set_cf(current + amount);
    std::cout << "[CoinPayment] Inserted coin: " << amount << ". Total: " << ds->get_cf() << std::endl;
    return true;
}
