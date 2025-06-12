// File: strategy/DisposeDrink1.h
// Purpose: Concrete strategy for dispensing drinks in VM1

#ifndef DISPOSE_DRINK_1_H
#define DISPOSE_DRINK_1_H

#include "DisposeDrink.h"
#include "../model/DataStore.h"

class DisposeDrink1 : public DisposeDrink
{
private:
    DataStore *ds;

public:
    DisposeDrink1(DataStore *ds) : ds(ds) {}
    void dispose_drink() override;
};

#endif
