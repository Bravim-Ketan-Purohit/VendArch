// File: strategy/CoinPayment.h
// Purpose: Concrete strategy for coin payment logic

#ifndef COIN_PAYMENT_H
#define COIN_PAYMENT_H

#include "PaymentStrategy.h"

class CoinPayment : public PaymentStrategy
{
public:
    bool pay(DataStore *ds, float amount) override;
};

#endif
