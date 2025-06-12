#include "DisposeAdditives1.h"
#include <iostream>
using namespace std;

DisposeAdditives1::DisposeAdditives1(DataStore *datastore)
{
    ds = datastore;
}

void DisposeAdditives1::dispose_additives()
{
    if (ds->get_additive(0))
    {
        cout << "[DisposeAdditives1] Dispensing sugar..." << endl;
    }
    else
    {
        cout << "[DisposeAdditives1] No additives to dispense." << endl;
    }
}
