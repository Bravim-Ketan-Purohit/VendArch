#include "DisposeAdditives2.h"
#include <iostream>
using namespace std;

DisposeAdditives2::DisposeAdditives2(DataStore *datastore)
{
    ds = datastore;
}

void DisposeAdditives2::dispose_additives()
{
    if (ds->get_additive(0))
    {
        cout << "[DisposeAdditives2] Dispensing sugar..." << endl;
    }
    else
    {
        cout << "[DisposeAdditives2] No additives to dispense." << endl;
    }
}
