#include "StorePrice2.h"
#include <iostream>

using namespace std;

StorePrice2::StorePrice2(DataStore *datastore)
{
    ds = datastore;
}

void StorePrice2::storePrice()
{
    float p = ds->get_temp_p();
    ds->set_price(p);
    cout << "[StorePrice2] Stored price: " << static_cast<int>(p) << " units into DataStore." << endl;
}
