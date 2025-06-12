// File: strategy/SetPrice1.h
// Purpose: Concrete strategy for applying price to DataStore in VM1

#ifndef SET_PRICE_1_H
#define SET_PRICE_1_H

#include "SetPrice.h"
#include "../model/DataStore.h"

class SetPrice1 : public SetPrice
{
private:
    DataStore *ds;

public:
    SetPrice1(DataStore *ds) : ds(ds) {}
    void set_price(float price) override;
};

#endif
