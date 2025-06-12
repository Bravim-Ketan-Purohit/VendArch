#include "ReturnCoins1.h"
#include <iostream>
using namespace std;

ReturnCoins1::ReturnCoins1(DataStore *datastore)
{
    ds = datastore;
}

void ReturnCoins1::return_coins()
{
    if (ds->get_cf() > 0)
    {
        cout << "[ReturnCoins1] Returning " << ds->get_cf() << " units as refund to user." << endl;
    }
    else
    {
        cout << "[ReturnCoins1] No remaining funds to return." << endl;
    }
}
