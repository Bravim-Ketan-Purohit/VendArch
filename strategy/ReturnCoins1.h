#ifndef RETURNCOINS1_H
#define RETURNCOINS1_H

#include "ReturnCoins.h"
#include "../model/DataStore.h"

class ReturnCoins1 : public ReturnCoins
{
private:
    DataStore *ds;

public:
    ReturnCoins1(DataStore *datastore);
    void return_coins() override;
};

#endif
