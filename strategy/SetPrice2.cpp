#include "SetPrice2.h"
#include <iostream>
using namespace std;

void SetPrice2::set_price(float price)
{
    cout << "[SetPrice2] Price set to: " << static_cast<int>(price) << " units (VM2)." << endl;
}
