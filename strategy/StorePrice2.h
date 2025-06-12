#ifndef STOREPRICE2_H
#define STOREPRICE2_H

#include "StorePrice.h"
#include "../model/DataStore.h"

class StorePrice2 : public StorePrice
{
private:
    DataStore *ds;

public:
    StorePrice2(DataStore *datastore);
    void storePrice() override;
};

#endif
