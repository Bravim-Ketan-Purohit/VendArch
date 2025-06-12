// File: strategy/PaymentStrategy.h
// Purpose: Defines abstract strategy interface for payment handling

#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include "../model/DataStore.h"

class PaymentStrategy
{
public:
    virtual bool pay(DataStore *ds, float amount) = 0;
    virtual ~PaymentStrategy() {}
};

#endif
