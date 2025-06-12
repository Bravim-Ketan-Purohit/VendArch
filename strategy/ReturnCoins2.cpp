#include "ReturnCoins2.h"
#include <iostream>
using namespace std;

ReturnCoins2::ReturnCoins2(DataStore *datastore)
{
    ds = datastore;
}

void ReturnCoins2::return_coins()
{
    if (ds->get_cf() > 0)
    {
        cout << "[ReturnCoins2] Returning " << ds->get_cf() << " units as refund to user." << endl;
    }
    else
    {
        cout << "[ReturnCoins2] No remaining funds to return." << endl;
    }
}
