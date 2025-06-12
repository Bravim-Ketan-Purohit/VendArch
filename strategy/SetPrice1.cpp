#include "SetPrice1.h"
#include <iostream>

void SetPrice1::set_price(float price)
{
    ds->set_price(price);
    std::cout << "[SetPrice1] Price set to: " << price << " units.\n";
}
