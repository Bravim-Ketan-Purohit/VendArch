#ifndef RETURNCOINS2_H
#define RETURNCOINS2_H

#include "ReturnCoins.h"
#include "../model/DataStore.h"

class ReturnCoins2 : public ReturnCoins
{
private:
    DataStore *ds;

public:
    ReturnCoins2(DataStore *datastore);
    void return_coins() override;
};

#endif
