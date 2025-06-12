#include "StorePrice1.h"
#include <iostream>
using namespace std;

StorePrice1::StorePrice1(DataStore *datastore)
{
    ds = datastore;
}

void StorePrice1::storePrice()
{
    float price = ds->get_temp_p(); // ✅ Accessor correct now
    ds->set_price(price);
    cout << "[StorePrice1] Stored price: " << price << " units into DataStore." << endl;
}
